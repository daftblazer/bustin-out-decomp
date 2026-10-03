#!/bin/sh
# Builds decomp-toolkit with the ProDG (GCC) analysis fixes in tools/dtk-prodg.patch
# and installs it as build/tools/dtk-prodg.
#
# Requires `cargo`. If it isn't on PATH, a toolchain is installed locally under
# build/rust (nothing is installed outside the project directory).
set -eu
cd "$(dirname "$0")/.."
ROOT="$(pwd)"
DTK_TAG="v1.8.3"
SRC="$ROOT/build/dtk-src"

if ! command -v cargo >/dev/null 2>&1; then
    export RUSTUP_HOME="$ROOT/build/rust/rustup" CARGO_HOME="$ROOT/build/rust/cargo"
    export PATH="$CARGO_HOME/bin:$PATH"
    if ! command -v cargo >/dev/null 2>&1; then
        curl -sSf https://sh.rustup.rs | sh -s -- -y --no-modify-path --profile minimal
    fi
fi

if [ ! -d "$SRC/.git" ]; then
    rm -rf "$SRC"
    git clone -q --depth 1 --branch "$DTK_TAG" https://github.com/encounter/decomp-toolkit.git "$SRC"
fi
git -C "$SRC" checkout -q -- .
git -C "$SRC" apply "$ROOT/tools/dtk-prodg.patch"
(cd "$SRC" && cargo build --release -j "${JOBS:-8}")
mkdir -p "$ROOT/build/tools"
cp "$SRC/target/release/dtk" "$ROOT/build/tools/dtk-prodg"
"$ROOT/build/tools/dtk-prodg" --version
