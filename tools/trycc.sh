#!/bin/sh
# Compile a snippet with ProDG and print its disassembly.
# Usage: tools/trycc.sh [-v VERSION] file.cpp [extra compiler flags...]
cd "$(dirname "$0")/.." || exit 1
V=3.7
if [ "$1" = "-v" ]; then V="$2"; shift 2; fi
SRC="$1"; shift
OUT="build/try/$(basename "$SRC" | sed 's/\.[^.]*$//').o"
mkdir -p build/try
env SN_NGC_PATH="build/compilers/ProDG/$V" build/tools/wibo "build/compilers/ProDG/$V/ngccc.exe" -O2 "$@" -c "$SRC" -o "$OUT" || exit 1
build/binutils/powerpc-eabi-objdump -dr --no-show-raw-insn "$OUT"
