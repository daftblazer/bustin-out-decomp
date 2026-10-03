#!/usr/bin/env python3
"""Quick raw disassembler for the original DOL: tools/ppcdis.py ADDR [COUNT]"""
import struct, sys
from pathlib import Path
from capstone import Cs, CS_ARCH_PPC, CS_MODE_32, CS_MODE_BIG_ENDIAN

DOL = Path(__file__).resolve().parent.parent / "orig/G4ME69/sys/main.dol"

def load(path=DOL):
    d = path.read_bytes()
    offs = struct.unpack(">18I", d[0:0x48]); addrs = struct.unpack(">18I", d[0x48:0x90]); sizes = struct.unpack(">18I", d[0x90:0xD8])
    return d, [(addrs[i], sizes[i], offs[i]) for i in range(18) if sizes[i]]

def read(d, secs, addr, n):
    for a, s, o in secs:
        if a <= addr < a + s:
            return d[o + addr - a : o + addr - a + n]
    raise SystemExit(f"address {addr:#x} not in DOL")

if __name__ == "__main__":
    addr = int(sys.argv[1], 16); count = int(sys.argv[2], 0) if len(sys.argv) > 2 else 32
    d, secs = load()
    md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)
    code = read(d, secs, addr, count * 4)
    for i in range(0, len(code), 4):
        w = code[i:i+4]; ins = list(md.disasm(w, addr + i))
        print(f"{addr+i:08X}  {w.hex()}  " + (f"{ins[0].mnemonic} {ins[0].op_str}" if ins else f".long 0x{w.hex()}"))
