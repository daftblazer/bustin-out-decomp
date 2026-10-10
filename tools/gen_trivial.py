#!/usr/bin/env python3
"""Generate source for the trivial functions of a game-code unit and keep those that match.

Usage: tools/gen_trivial.py START END NAME [--max-size 0x40]
  START END   address range of the unit (END = start of the next unit, including its static initialiser)
  NAME        source name, e.g. sims/Unk802372E4

Recognised shapes (all at -O2, GCC 2.95): an empty function, `li; stw` setters, `stfs`/`lfs` accessors,
`addi r3` (address of a member), `lwz r3` getters, small-data globals through r13, runs of constant or
argument stores (several source orders are tried), and virtual destructors that store a vtable and delete.
Each generated function is named by address with an asm label so it keeps the original symbol.

It adds the split to config/G4ME69/splits.txt and the object to configure.py when they are missing,
writes src/NAME.cpp, compiles it with tools/tu.sh and drops every function that does not print MATCH.
"""
import itertools, pickle, re, subprocess, sys
from pathlib import Path

R = Path(__file__).resolve().parent.parent
SDA = 0x803833E0


def num(x):
    return int(x, 16) if "x" in x else int(x)


def functions(lo, hi, maxsize):
    rows = []
    for l in open(R / "config/G4ME69/symbols.txt"):
        m = re.match(r"(\S+) = \.text:0x(\w+); // type:function size:0x(\w+)", l)
        if m:
            a = int(m.group(2), 16)
            if lo <= a < hi and int(m.group(3), 16) <= maxsize:
                rows.append((a, int(m.group(3), 16), m.group(1)))
    return rows


def disasm(a, size):
    out = subprocess.run([str(R / ".venv/bin/python"), str(R / "tools/ppcdis.py"), "%X" % a, str(size // 4)],
                         capture_output=True, text=True).stdout.split("\n")
    return [re.sub(r"^[0-9A-F]+\s+[0-9a-f]+\s+", "", l).strip() for l in out if l.strip()]


def gname(off):
    return "lbl_%08X" % ((SDA + off) & 0xFFFFFFFF)


def simple(a, name, ins):
    """code for the one-shape functions, or None"""
    def m(p, i=0):
        return re.fullmatch(p, ins[i]) if i < len(ins) else None
    if ins == ["blr"]:
        return "void %s(void* self)" % name, "", set()
    if len(ins) == 3 and m(r"li r0, (-?\w+)") and m(r"stw r0, (-?\w+)\(r3\)", 1) and ins[2] == "blr":
        v = num(m(r"li r0, (-?\w+)").group(1)); o = num(m(r"stw r0, (-?\w+)\(r3\)", 1).group(1))
        return "void %s(char* self)" % name, "    *(int*)(self + 0x%X) = %d;\n" % (o, v), set()
    if len(ins) == 2 and m(r"stfs f1, (-?\w+)\(r3\)") and ins[1] == "blr":
        o = num(m(r"stfs f1, (-?\w+)\(r3\)").group(1))
        return "void %s(char* self, float v)" % name, "    *(float*)(self + 0x%X) = v;\n" % o, set()
    if len(ins) == 2 and m(r"lfs f1, (-?\w+)\(r3\)") and ins[1] == "blr":
        o = num(m(r"lfs f1, (-?\w+)\(r3\)").group(1))
        return "float %s(char* self)" % name, "    return *(float*)(self + 0x%X);\n" % o, set()
    if len(ins) == 2 and m(r"addi r3, r3, (-?\w+)") and ins[1] == "blr":
        o = num(m(r"addi r3, r3, (-?\w+)").group(1))
        return "char* %s(char* self)" % name, "    return self + 0x%X;\n" % o, set()
    if len(ins) == 2 and m(r"lwz r3, (-?\w+)\(r3\)") and ins[1] == "blr":
        o = num(m(r"lwz r3, (-?\w+)\(r3\)").group(1))
        return "int %s(char* self)" % name, "    return *(int*)(self + 0x%X);\n" % o, set()
    if len(ins) == 2 and m(r"lwz r3, (-?\w+)\(r13\)") and ins[1] == "blr":
        g = gname(num(m(r"lwz r3, (-?\w+)\(r13\)").group(1)))
        return "int %s(void)" % name, "    return %s;\n" % g, {"extern int %s;" % g}
    if len(ins) == 3 and m(r"li r0, (-?\w+)") and m(r"stw r0, (-?\w+)\(r13\)", 1) and ins[2] == "blr":
        v = num(m(r"li r0, (-?\w+)").group(1)); g = gname(num(m(r"stw r0, (-?\w+)\(r13\)", 1).group(1)))
        return "void %s(void)" % name, "    %s = %d;\n" % (g, v), {"extern int %s;" % g}
    return None


def destructor(a, name, ins):
    if not (ins[:3] == ["stwu r1, -8(r1)", "mflr r0", "stw r0, 0xc(r1)"] and ins[-1] == "blr"):
        return None
    flat = " ; ".join(ins)
    m = re.fullmatch(r"stwu r1, -8\(r1\) ; mflr r0 ; stw r0, 0xc\(r1\) ; lis r9, (-?\w+) ; andi\. r0, r4, 1 ; "
                     r"addi r9, r9, (-?\w+) ; stw r9, (\w+)\(r3\) ; beq \w+ ; bl (0x[0-9a-f]+) ; lwz r0, 0xc\(r1\) ; "
                     r"mtlr r0 ; addi r1, r1, 8 ; blr", flat)
    if m:
        vt = "lbl_%08X" % (((num(m.group(1)) << 16) + num(m.group(2))) & 0xFFFFFFFF)
        callee = "fn_%08X" % num(m.group(4))
        body = "    *(char**)(self + %s) = %s;\n    if (flag & 1) {\n        %s(self);\n    }\n" % (m.group(3), vt, callee)
        return "void %s(char* self, int flag)" % name, body, {"extern char %s[];" % vt, 'extern "C" void %s(void*);' % callee}
    m = re.fullmatch(r"stwu r1, -8\(r1\) ; mflr r0 ; stw r0, 0xc\(r1\) ; andi\. r0, r4, 1 ; beq \w+ ; bl (0x[0-9a-f]+) ; "
                     r"lwz r0, 0xc\(r1\) ; mtlr r0 ; addi r1, r1, 8 ; blr", flat)
    if m:
        callee = "fn_%08X" % num(m.group(1))
        return ("void %s(char* self, int flag)" % name,
                "    if (flag & 1) {\n        %s(self);\n    }\n" % callee, {'extern "C" void %s(void*);' % callee})
    return None


def stores(a, name, ins):
    regs = {}; sts = []
    if ins[-1] != "blr":
        return None
    for i in ins[:-1]:
        m = re.fullmatch(r"li r(\d+), (-?\w+)", i)
        if m:
            regs[m.group(1)] = num(m.group(2)); continue
        m = re.fullmatch(r"(stw|stb|sth) r(\d+), (-?\w+)\(r(3|13)\)", i)
        if m:
            op, r, off, base = m.groups()
            if r == "4":
                sts.append((op, "arg", num(off), base))
            elif r in regs:
                sts.append((op, regs[r], num(off), base))
            else:
                return None
            continue
        return None
    return sts or None


def store_code(name, sts, order):
    body = []; decl = set()
    for i in order:
        op, val, off, base = sts[i]
        ty = {"stw": "int", "stb": "char", "sth": "short"}[op]
        v = "a" if val == "arg" else str(val)
        if base == "13":
            g = gname(off); decl.add("extern %s %s;" % (ty, g)); body.append("    %s = %s;" % (g, v))
        else:
            body.append("    *(%s*)(self + 0x%X) = %s;" % (ty, off, v))
    hasarg = any(s[1] == "arg" for s in sts)
    return "void %s(char* self%s)" % (name, ", int a" if hasarg else ""), "\n".join(body) + "\n", decl


def render(a, name, sig, body):
    return "// 0x%08X\n%s asm(\"%s\");\n%s\n{\n%s}\n\n" % (a, sig, name, sig, body)


def assemble(header, decls, chunks):
    chunks = sorted(chunks, key=lambda c: c[0])
    return header + "".join(sorted(decls)) + "\n" + "".join(c[1] for c in chunks)


def run_tu(srcname):
    r = subprocess.run([str(R / "tools/tu.sh"), "src/%s.cpp" % srcname], cwd=R, capture_output=True, text=True)
    res = {}
    for l in (r.stdout + r.stderr).split("\n"):
        m = re.match(r"(\S+) @ \w+: .*", l)
        if m:
            res[m.group(1)] = "-> MATCH" in l
    return res, r.stdout + r.stderr


def register(lo, hi, srcname):
    sp = R / "config/G4ME69/splits.txt"
    s = sp.read_text()
    if srcname + ".cpp:" not in s:
        # keep splits in address order: insert before the first entry that starts above this unit
        entries = list(re.finditer(r"(?m)^(\S+):\n((?:\t.*\n)+)", s))
        pos = None
        for e in entries:
            t = re.search(r"\.text\s+start:0x([0-9A-F]+)", e.group(2))
            if t and int(t.group(1), 16) > lo:
                pos = e.start(); break
        new = "%s.cpp:\n\t.text       start:0x%08X end:0x%08X\n\n" % (srcname, lo, hi)
        s = s[:pos] + new + s[pos:] if pos is not None else s.rstrip("\n") + "\n\n" + new
        sp.write_text(s)
    cf = R / "configure.py"
    c = cf.read_text()
    if '"%s.cpp"' % srcname not in c:
        c = c.replace('            Object(NonMatching, "sims/Unk80049ADC.cpp"),\n',
                      '            Object(NonMatching, "sims/Unk80049ADC.cpp"),\n            Object(NonMatching, "%s.cpp"),\n' % srcname, 1)
        cf.write_text(c)


def main():
    lo, hi, name = int(sys.argv[1], 16), int(sys.argv[2], 16), sys.argv[3]
    maxsize = 0x40
    if "--max-size" in sys.argv:
        maxsize = int(sys.argv[sys.argv.index("--max-size") + 1], 16)
    register(lo, hi, name)
    header = "// Game code at 0x%08X-0x%08X: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.\n" \
             "// Each is named by address with an asm label so it keeps the symbol of the original.\n\n" % (lo, hi)
    path = R / ("src/%s.cpp" % name)
    chunks = []   # (addr, text)
    decls = set()
    multi = []
    for a, size, fn in functions(lo, hi, maxsize):
        ins = disasm(a, size)
        r = simple(a, fn, ins) or destructor(a, fn, ins)
        if r:
            sig, body, d = r
            chunks.append((a, render(a, fn, sig, body))); decls |= d
            continue
        sts = stores(a, fn, ins)
        if sts:
            multi.append((a, fn, sts))
    path.write_text(assemble(header, decls, chunks))
    res, _ = run_tu(name)
    # drop what does not match
    keep = [c for c in chunks if res.get(re.search(r'asm\("(\w+)"\)', c[1]).group(1))]
    dropped = len(chunks) - len(keep)
    chunks = keep
    path.write_text(assemble(header, decls, chunks))
    print("simple: %d kept, %d dropped" % (len(chunks), dropped))
    # store runs: try several source orders each
    for a, fn, sts in multi:
        n = len(sts)
        orders = [list(range(n))]
        if n > 1:
            orders.append(list(range(1, n)) + [0])
        orders += [list(p) for p in itertools.permutations(range(n)) if list(p) not in orders][:10]
        for o in orders:
            sig, body, d = store_code(fn, sts, o)
            trial = chunks + [(a, render(a, fn, sig, body))]
            path.write_text(assemble(header, decls | d, trial))
            res, _ = run_tu(name)
            if res.get(fn):
                chunks = trial; decls |= d
                break
        else:
            path.write_text(assemble(header, decls, chunks))
    path.write_text(assemble(header, decls, chunks))
    res, _ = run_tu(name)
    print("final: %d functions, %d matching" % (len(res), sum(res.values())))


if __name__ == "__main__":
    main()
