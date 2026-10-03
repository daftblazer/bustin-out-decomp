#!/usr/bin/env python3
"""Compile one file with ProDG using the template repository (-frepo).

The original build used GCC's template repository: template instances are not
emitted where they are used; the link step assigns each one to a single object
(the first in link order that can provide it) and recompiles that object with
the instance emitted as a global symbol. This script reproduces the result for
one object: it compiles, marks every template instance the object itself needs
and can provide as chosen in the .rpo file, and recompiles until nothing changes.

Which instances an object provides is taken from the project configuration:
with --unit NAME (the unit's name in splits.txt), exactly those offered
instances whose mangled name is a symbol inside that unit's address ranges in
symbols.txt are emitted. Without --unit, every instance the object itself
needs is emitted (useful for scratch files).

Usage: tools/prodg_cc.py [--unit NAME] -- COMPILER_COMMAND... -c SRC -o OBJ
"""
import os, subprocess, sys
from pathlib import Path

root = Path(__file__).resolve().parent.parent
nm = root / "build/binutils/powerpc-eabi-nm"

def unit_symbols(unit):
    """Names of all symbols inside the address ranges splits.txt gives to `unit`."""
    import re
    ranges = []; current = None
    for line in open(root / "config/G4ME69/splits.txt"):
        if line and not line[0].isspace():
            current = line.strip().rstrip(":").split(":")[0]
        elif current == unit:
            m = re.search(r"start:0x([0-9A-Fa-f]+) end:0x([0-9A-Fa-f]+)", line)
            if m: ranges.append((int(m.group(1), 16), int(m.group(2), 16)))
    if not ranges: sys.exit(f"unit {unit} not found in splits.txt")
    names = set()
    for line in open(root / "config/G4ME69/symbols.txt"):
        m = re.match(r"(\S+) = \.\w+:0x([0-9A-F]+);", line)
        if m and any(a <= int(m.group(2), 16) < b for a, b in ranges): names.add(m.group(1))
    return names

def main():
    args = sys.argv[1:]
    only = None
    if args[0] == "--unit":
        only = unit_symbols(args[1]); args = args[2:]
    assert args[0] == "--"; cmd = args[1:]
    src = Path(cmd[cmd.index("-c") + 1]); obj = Path(cmd[cmd.index("-o") + 1])
    # cc1plus keeps the repository next to where it runs, named after the source.
    rpo = Path.cwd() / (src.stem + ".rpo")
    if rpo.exists(): rpo.unlink()
    for _ in range(20):
        r = subprocess.run(cmd)
        if r.returncode: sys.exit(r.returncode)
        if not rpo.exists(): break
        out = subprocess.run([nm, obj], capture_output=True, text=True, check=True).stdout
        undefined = {l.split()[-1] for l in out.splitlines() if " U " in l}
        lines = rpo.read_text().splitlines(); changed = False
        for i, line in enumerate(lines):
            if line.startswith("O ") and (line[2:] in only if only is not None else line[2:] in undefined):
                lines[i] = "C" + line[1:]; changed = True
        if not changed: break
        rpo.write_text("\n".join(lines) + "\n")
    else:
        sys.exit("template repository did not converge")
    # Keep the repository beside the object so parallel builds don't collide on it.
    if rpo.exists(): os.replace(rpo, obj.with_suffix(".rpo"))

main()
