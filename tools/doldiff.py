#!/usr/bin/env python3
"""Compare the rebuilt DOL against the original, section by section.
Usage: tools/doldiff.py [built.dol] [orig.dol]"""
import struct, sys
from pathlib import Path
root = Path(__file__).resolve().parent.parent
built = Path(sys.argv[1]) if len(sys.argv) > 1 else root / "build/G4ME69/main.dol"
orig = Path(sys.argv[2]) if len(sys.argv) > 2 else root / "orig/G4ME69/sys/main.dol"

def parse(p):
    d = p.read_bytes()
    o = struct.unpack(">18I", d[0:0x48]); a = struct.unpack(">18I", d[0x48:0x90]); s = struct.unpack(">18I", d[0x90:0xD8])
    return d, [(i, o[i], a[i], s[i]) for i in range(18) if s[i]], struct.unpack(">3I", d[0xD8:0xE4])

bd, bs, bx = parse(built); od, os_, ox = parse(orig)
print(f"size: built {len(bd):#x} orig {len(od):#x}")
print(f"bss/entry: built {[hex(v) for v in bx]} orig {[hex(v) for v in ox]}")
for b, o in zip(bs, os_):
    flag = "" if b == o else "   <-- header differs"
    print(f"sec{o[0]:2d} orig off {o[1]:#08x} addr {o[2]:#010x} size {o[3]:#08x} | built off {b[1]:#08x} addr {b[2]:#010x} size {b[3]:#08x}{flag}")
if len(bs) != len(os_): print(f"section count differs: built {len(bs)} orig {len(os_)}")
total = 0
for (i, off, addr, size) in os_:
    m = next((x for x in bs if x[2] == addr), None)
    if not m: print(f"sec{i} @ {addr:#x}: missing in built"); continue
    n = min(size, m[3]); diffs = [k for k in range(0, n) if od[off + k] != bd[m[1] + k]]
    total += len(diffs)
    if diffs:
        print(f"sec{i} @ {addr:#x}: {len(diffs)} differing bytes; first at " + ", ".join(f"{addr + k:#010x}" for k in diffs[:6]))
print("IDENTICAL" if bd == od else f"NOT identical ({total} differing section bytes)")
