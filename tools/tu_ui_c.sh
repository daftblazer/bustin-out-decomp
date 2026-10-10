#!/bin/sh
# Like tu_ui.sh for a plain C source that belongs to a unit already listed in
# splits.txt: tools/tu_ui_c.sh src/ui/Unk8014A18C_c.c ui/Unk8014A18C.cpp [-v]
cd "$(dirname "$0")/.." || exit 1
SRC="$1"; UNIT="$2"; shift 2
OUT="build/try/$(basename "$SRC" | sed 's/\.[^.]*$//').o"
mkdir -p build/try
V="${PRODG:-3.7}"
.venv/bin/python tools/prodg_cc.py --unit "$UNIT" -- env SN_NGC_PATH="build/compilers/ProDG/$V" build/tools/wibo "build/compilers/ProDG/$V/ngccc.exe" -O0 -G8 -fno-weak -fsigned-char -Iinclude -Ibuild/G4ME69/include -c "$SRC" -o "$OUT" || exit 1
FNCMP_UNIT="$UNIT" .venv/bin/python tools/fncmp.py "$OUT" "$@"
