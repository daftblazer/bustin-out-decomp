#!/usr/bin/env python3
"""Find references to an address in the original DOL: tools/findref.py ADDR
Reports raw 32-bit words and lis+addi/ori/load/store pairs (within 8 instructions)."""
import struct, sys
sys.path.insert(0, __file__.rsplit("/", 1)[0])
from ppcdis import load

def refs(target, d=None, secs=None):
    if d is None: d, secs = load()
    out = []
    for a, s, o in secs:
        for i in range(0, s - 3, 4):
            if struct.unpack(">I", d[o+i:o+i+4])[0] == target: out.append((a + i, "word"))
    for a, s, o in secs[:2]:
        ws = struct.unpack(f">{s//4}I", d[o:o+s//4*4])
        for i, w in enumerate(ws):
            if w >> 26 != 15 or (w >> 16) & 31: continue
            rd = (w >> 21) & 31; hi = (w & 0xFFFF) << 16
            for j in range(i + 1, min(i + 9, len(ws))):
                w2 = ws[j]; op = w2 >> 26; ra = (w2 >> 16) & 31; imm = w2 & 0xFFFF
                if op == 24 and ((w2 >> 21) & 31) == rd and (hi | imm) == target: out.append((a + i*4, f"lis/ori @+{(j-i)*4:#x}"))
                elif (op == 14 or 32 <= op <= 55) and ra == rd and (hi + (imm - 0x10000 if imm & 0x8000 else imm)) & 0xFFFFFFFF == target:
                    out.append((a + i*4, f"lis/op{op} @+{(j-i)*4:#x}"))
    return out

if __name__ == "__main__":
    for addr, kind in refs(int(sys.argv[1], 16)): print(f"{addr:08X} {kind}")
