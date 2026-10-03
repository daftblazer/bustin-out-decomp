#!/usr/bin/env python3
"""Rename symbols in symbols.txt: tools/rename.py OLD NEW [OLD NEW ...]"""
import re, sys
from pathlib import Path
p = Path(__file__).resolve().parent.parent / "config/G4ME69/symbols.txt"
s = p.read_text()
args = sys.argv[1:]
for old, new in zip(args[0::2], args[1::2]):
    s, n = re.subn(rf"^{re.escape(old)} = ", f"{new} = ", s, flags=re.M)
    if n != 1: sys.exit(f"{old}: {n} matches")
p.write_text(s)
