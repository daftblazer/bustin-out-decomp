#!/bin/sh
# Print the original disassembly of one function, compactly.
# Usage: tools/fnasm.sh SYMBOL   (searches build/G4ME69/asm)
cd "$(dirname "$0")/.." || exit 1
f=$(grep -rl "^\.fn $1," build/G4ME69/asm | head -1)
[ -n "$f" ] || { echo "not found: $1" >&2; exit 1; }
sed -n "/^\.fn $1,/,/^\.endfn $1/p" "$f" | sed 's#/\* \(........\) ........  .. .. .. .. \*/#\1#' | cut -c1-100
