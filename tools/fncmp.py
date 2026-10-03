#!/usr/bin/env python3
"""Compare a compiled function against the original DOL, masking relocated fields.

Usage: tools/fncmp.py OBJECT [-v]              (all functions named in symbols.txt)
       tools/fncmp.py OBJECT SYMBOL ADDR [-v]
  OBJECT  compiled ELF object (e.g. from tools/trycc.sh, in build/try/)
  SYMBOL  mangled function symbol in OBJECT
  ADDR    address of the original function (hex)
"""
import struct, subprocess, sys, re
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent))
from ppcdis import load, read
from capstone import Cs, CS_ARCH_PPC, CS_MODE_32, CS_MODE_BIG_ENDIAN

root = Path(__file__).resolve().parent.parent
objdump = root / "build/binutils/powerpc-eabi-objdump"
MASKS = {"R_PPC_REL24": 0x03FFFFFC, "R_PPC_REL14": 0x0000FFFC, "R_PPC_EMB_SDA21": 0x001FFFFF,
         "R_PPC_ADDR16_HA": 0xFFFF, "R_PPC_ADDR16_LO": 0xFFFF, "R_PPC_ADDR16_HI": 0xFFFF, "R_PPC_ADDR32": 0xFFFFFFFF}

SIZES = {}  # original function sizes by address, when known from symbols.txt

def main():
    if len(sys.argv) == 2 or sys.argv[2] == "-v":
        # Compare every function in OBJECT that is named in symbols.txt
        table = {}
        for line in open(root / "config/G4ME69/symbols.txt"):
            m = re.match(r"(\S+) = \.\w+:0x([0-9A-F]+); // type:function size:0x([0-9A-F]+)", line)
            if m: table[m.group(1)] = int(m.group(2), 16); SIZES[int(m.group(2), 16)] = int(m.group(3), 16)
        out = subprocess.run([objdump, "-dr", "-z", sys.argv[1]], capture_output=True, text=True, check=True).stdout
        ok = True
        for sym in re.findall(r"^[0-9a-f]+ <(\S+)>:$", out, re.M):
            if sym in table: ok &= compare(out, sys.argv[1], sym, table[sym])
            else: print(f"{sym}: not in symbols.txt (skipped)")
        sys.exit(0 if ok else 1)
    obj, sym, addr = sys.argv[1], sys.argv[2], int(sys.argv[3], 16)
    out = subprocess.run([objdump, "-dr", "-z", obj], capture_output=True, text=True, check=True).stdout
    sys.exit(0 if compare(out, obj, sym, addr) else 1)

def compare(out, obj, sym, addr):
    m = re.search(rf"^[0-9a-f]+ <{re.escape(sym)}>:\n(.*?)(?=^\s*$|\Z)", out, re.M | re.S)
    if not m: sys.exit(f"symbol {sym} not found in {obj}")
    verbose = "-v" in sys.argv
    words, relocs = [], {}
    for line in m.group(1).splitlines():
        r = re.match(r"\s+([0-9a-f]+):\s+(R_PPC_\w+)\s+(\S+)", line)
        if r: relocs[int(r.group(1), 16) & ~3] = (r.group(2), r.group(3)); continue
        i = re.match(r"\s*([0-9a-f]+):\s+((?:[0-9a-f]{2} ){4})", line)
        if i: words.append((int(i.group(1), 16), int(i.group(2).replace(" ", ""), 16)))
    base = words[0][0]
    d, secs = load()
    orig = struct.unpack(f">{len(words)}I", read(d, secs, addr, len(words) * 4))
    md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)
    dis = lambda w, a: (lambda l: f"{l[0].mnemonic} {l[0].op_str}" if l else f".long {w:#x}")(list(md.disasm(struct.pack(">I", w), a)))
    bad = 0
    for (off, w), o in zip(words, orig):
        rel = relocs.get(off)
        mask = MASKS.get(rel[0], 0) if rel else 0
        # intra-function branches carry no relocation after assembly; compare them as-is
        same = (w & ~mask) == (o & ~mask)
        a = addr + off - base
        if not same: bad += 1
        note = f"   [{rel[1]}]" if rel else ""
        if not same or verbose:
            print(f"{'  ' if same else '!!'} {a:08X}  orig: {dis(o, a):32s} mine: {dis(w, a)}{note}")
    # A function of the wrong length never matches, even if the common part agrees.
    orig_len = SIZES.get(addr, len(words) * 4) // 4
    if orig_len != len(words):
        print(f"{sym} @ {addr:08X}: {len(words)} instructions (original has {orig_len}), {bad} mismatching in the common part")
        return False
    print(f"{sym} @ {addr:08X}: {len(words)} instructions, {bad} mismatching" + ("  -> MATCH" if not bad else ""))
    return not bad

main()
