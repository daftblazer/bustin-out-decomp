#!/bin/sh
# Like tu.sh, for the unoptimised UI (Apt) library at 0x8012AD10-0x80151F80: -O0, C or C++ by extension.
# Usage: tools/tu0.sh src/ui/Foo.c [-v]
cd "$(dirname "$0")/.." || exit 1
SRC="$1"; shift
OUT="build/try/$(basename "$SRC" | sed 's/\.[^.]*$//').o"
mkdir -p build/try
V="${PRODG:-3.7}"
UNIT="${SRC#src/}"
env SN_NGC_PATH="build/compilers/ProDG/$V" build/tools/wibo "build/compilers/ProDG/$V/ngccc.exe" -O0 -G8 -fno-weak -fsigned-char -Ilibs/include -Iinclude -Ibuild/G4ME69/include -c "$SRC" -o "$OUT" || exit 1
FNCMP_UNIT="$UNIT" .venv/bin/python tools/fncmp.py "$OUT" "$@"
