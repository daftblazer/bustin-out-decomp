#!/usr/bin/env python3
"""Reorder the functions of a source file by original address.

Each function must be introduced by a comment line `// 0xADDRESS` at column 0.
Everything before the first such comment is kept as the file's preamble. The
original object has its functions in address order, so the source must too
before the unit can be linked.

Usage: tools/sort_functions.py src/path/file.cpp
"""
import re, sys
path = sys.argv[1]
text = open(path).read()
parts = re.split(r"(?m)^(?=// 0x[0-9A-Fa-f]{8}\b)", text)
head, blocks = parts[0], parts[1:]
blocks = [b if b.endswith("\n\n") else b.rstrip("\n") + "\n\n" for b in blocks]
blocks.sort(key=lambda b: int(re.match(r"// 0x([0-9A-Fa-f]{8})", b).group(1), 16))
open(path, "w").write(head + "".join(blocks).rstrip("\n") + "\n")
print(f"{len(blocks)} functions sorted")
