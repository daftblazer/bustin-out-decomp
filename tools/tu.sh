#!/bin/sh
# Compile one source file with the project flags and compare all of its functions
# against the original. Usage: tools/tu.sh src/sims/SimsApp.cpp [-v]
cd "$(dirname "$0")/.." || exit 1
SRC="$1"; shift
OUT="build/try/$(basename "$SRC" | sed 's/\.[^.]*$//').o"
mkdir -p build/try
V="${PRODG:-3.7}"
env SN_NGC_PATH="build/compilers/ProDG/$V" build/tools/wibo "build/compilers/ProDG/$V/ngccc.exe" -O2 -G8 -fno-weak -Iinclude -Ibuild/G4ME69/include -c "$SRC" -o "$OUT" || exit 1
.venv/bin/python tools/fncmp.py "$OUT" "$@"
