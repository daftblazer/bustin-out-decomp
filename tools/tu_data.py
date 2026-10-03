#!/usr/bin/env python3
"""Estimate which data belongs to each translation unit.

For every code object in build/G4ME69/asm, collect the data symbols its code
references. A symbol referenced by exactly one unit almost certainly belongs to
it (string literals, float constants, statics, vtables), so the hull of those
"exclusive" symbols approximates the unit's range in each data section.

Usage: tools/tu_data.py [-n COUNT] [-s SECTION] [UNIT_SUBSTRING]
  Prints, per unit in link order, the exclusive range in each data section.
  With UNIT_SUBSTRING, also lists that unit's exclusive symbols.
"""
import re, sys, bisect
from pathlib import Path
from collections import defaultdict

root = Path(__file__).resolve().parent.parent
asm_dir = root / "build/G4ME69/asm"
SECTIONS = [".rodata", ".data", ".bss", ".sdata", ".sbss", ".sdata2"]

def main():
    args = sys.argv[1:]; count = None; only = None; pick = None
    while args:
        a = args.pop(0)
        if a == "-n": count = int(args.pop(0))
        elif a == "-s": only = args.pop(0)
        else: pick = a
    syms = {}
    for line in open(root / "config/G4ME69/symbols.txt"):
        m = re.match(r"(\S+) = (\.\w+):0x([0-9A-F]+);(.*)", line)
        if m: syms[m.group(1)] = (m.group(2), int(m.group(3), 16), m.group(4))
    units = []  # (text start, name, set of data symbols)
    for path in asm_dir.rglob("*.s"):
        text = path.read_text()
        m = re.search(r"^\.fn (\S+),", text, re.M)
        if not m or m.group(1) not in syms or syms[m.group(1)][0] != ".text": continue
        refs = {s for s in re.findall(r"[A-Za-z_.$][\w.$]*", text) if s in syms and syms[s][0] in SECTIONS}
        units.append((syms[m.group(1)][1], str(path.relative_to(asm_dir)), refs))
    units.sort()
    users = defaultdict(set)
    for i, (_, _, refs) in enumerate(units):
        for s in refs: users[s].add(i)
    for i, (start, name, refs) in enumerate(units[:count]):
        excl = sorted((syms[s][1], s) for s in refs if len(users[s]) == 1)
        cols = []
        for sec in SECTIONS:
            if only and sec != only: continue
            a = [x for x in excl if syms[x[1]][0] == sec]
            cols.append(f"{sec} {a[0][0]:08X}-{a[-1][0]:08X} ({len(a)})" if a else f"{sec} -")
        print(f"{start:08X} {name:34s} " + "  ".join(cols))
        if pick and pick in name:
            for addr, s in excl:
                if only and syms[s][0] != only: continue
                print(f"    {syms[s][0]:8s} {addr:08X} {s}{syms[s][2][:60]}")

main()
