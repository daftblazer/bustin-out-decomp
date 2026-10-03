#!/usr/bin/env python3
"""Compare a compiled function against the original DOL, masking relocated fields.

Usage: tools/fncmp.py OBJECT SYMBOL ADDR
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

def main():
    obj, sym, addr = sys.argv[1], sys.argv[2], int(sys.argv[3], 16)
    out = subprocess.run([objdump, "-dr", "-z", obj], capture_output=True, text=True, check=True).stdout
    m = re.search(rf"^[0-9a-f]+ <{re.escape(sym)}>:\n(.*?)(?=^\s*$|\Z)", out, re.M | re.S)
    if not m: sys.exit(f"symbol {sym} not found in {obj}")
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
        if not same or "-v" in sys.argv:
            print(f"{'  ' if same else '!!'} {a:08X}  orig: {dis(o, a):32s} mine: {dis(w, a)}{note}")
    print(f"{sym} @ {addr:08X}: {len(words)} instructions, {bad} mismatching" + ("  -> MATCH" if not bad else ""))
    sys.exit(1 if bad else 0)

main()
