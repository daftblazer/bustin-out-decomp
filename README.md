<p align="center">
  <a href="https://github.com/daftblazer/bustin-out-decomp">
    <img src="images/logo.png" alt="The Sims: Bustin' Out Decompilation Project" width="338">
  </a>
</p>

<h1 align="center">The Sims: Bustin' Out (GameCube) decompilation</h1>

## About

A work-in-progress matching decompilation of *The Sims: Bustin' Out* for the Nintendo GameCube
(USA, `G4ME69`). The goal is C++ source that compiles, with the game's original compiler, to an
executable byte-identical to the one on the disc.

No game assets or code from the disc are included. You need your own copy.

| | |
|---|---|
| Version | USA, `G4ME69`, revision 0 (`NGC Sims Bustin Out Build 2.1.3.31-1i`) |
| `main.dol` SHA-1 | `26f0bf319a5fd3ea3d3d86e6117fbc78e259231c` |
| Engine | Edge of Reality "EOR Engine v2.0" (built Nov 13 2003) |
| Toolchain | SN Systems ProDG for GameCube (`ngccc`, GCC 2.95.2) and `ngcld`, **not** Metrowerks |

## Progress

<!-- progress:start -->

<p align="center">
  <img src="https://img.shields.io/badge/Code_matched-3.77%25-3828f7" alt="Code matched: 3.77%">
  <img src="https://img.shields.io/badge/Functions_matched-544_%2F_10,848-3828f7" alt="Functions matched: 544 / 10,848">
  <img src="https://img.shields.io/badge/Linked_from_source-5_files-3828f7" alt="Linked from source: 5 files">
</p>

| Part of the binary | Functions | Code matched | |
|---|---:|---:|---|
| Game code (`sims/`) | 544 / 3,289 | 9.39% | `██░░░░░░░░░░░░░░░░░░` |
| EOR engine (`engine/`) | 0 / 5,855 | 0.00% | `░░░░░░░░░░░░░░░░░░░░` |
| C/C++ runtime and libraries | 0 / 780 | 0.00% | `░░░░░░░░░░░░░░░░░░░░` |
| Dolphin SDK (Metrowerks) | 0 / 830 | 0.00% | `░░░░░░░░░░░░░░░░░░░░` |
| SN debugger stub (`libsn`) | 0 / 86 | 0.00% | `░░░░░░░░░░░░░░░░░░░░` |
| **Whole executable** | **544 / 10,848** | **3.77%** | `█░░░░░░░░░░░░░░░░░░░` |

A function counts as matched only when its C++ source compiles to the original bytes.
The Dolphin SDK parts were built with a different compiler and are not decompiled by hand here.

<details>
<summary>Source files (26)</summary>

| File | Functions | Code matched | | Linked from source |
|---|---:|---:|---|:---:|
| `src/sims/ECheats.cpp` | 26 / 30 | 29.3% | `███░░░░░░░` |  |
| `src/sims/ERFont.cpp` | 23 / 27 | 31.2% | `███░░░░░░░` |  |
| `src/sims/ERRleTexture.cpp` | 21 / 21 | 100.0% | `██████████` | yes |
| `src/sims/ESimsApp.cpp` | 36 / 41 | 60.6% | `██████░░░░` |  |
| `src/sims/ESimsCam.cpp` | 31 / 37 | 61.9% | `██████░░░░` |  |
| `src/sims/ESimsDataManager.cpp` | 70 / 70 | 100.0% | `██████████` |  |
| `src/sims/Unk800052C8.cpp` | 3 / 3 | 100.0% | `██████████` | yes |
| `src/sims/Unk80026864.cpp` | 60 / 78 | 38.2% | `████░░░░░░` |  |
| `src/sims/Unk8002EFAC.cpp` | 17 / 21 | 38.6% | `████░░░░░░` |  |
| `src/sims/Unk800315FC.cpp` | 21 / 24 | 72.4% | `███████░░░` |  |
| `src/sims/Unk80033974.cpp` | 20 / 38 | 26.6% | `███░░░░░░░` |  |
| `src/sims/Unk80039E78.cpp` | 5 / 7 | 37.5% | `████░░░░░░` |  |
| `src/sims/Unk8003AA6C.cpp` | 14 / 16 | 41.2% | `████░░░░░░` |  |
| `src/sims/Unk8003B870.cpp` | 4 / 6 | 21.9% | `██░░░░░░░░` |  |
| `src/sims/Unk8003DE78.cpp` | 5 / 5 | 100.0% | `██████████` | yes |
| `src/sims/Unk800401FC.cpp` | 37 / 51 | 36.4% | `████░░░░░░` |  |
| `src/sims/Unk80044D84.cpp` | 7 / 7 | 100.0% | `██████████` | yes |
| `src/sims/Unk800454AC.cpp` | 23 / 54 | 12.6% | `█░░░░░░░░░` |  |
| `src/sims/cas/CASSelectors.cpp` | 22 / 27 | 43.0% | `████░░░░░░` |  |
| `src/sims/cas/CASSim.cpp` | 21 / 38 | 27.1% | `███░░░░░░░` |  |
| `src/sims/cas/CASSkin.cpp` | 20 / 26 | 28.1% | `███░░░░░░░` |  |
| `src/sims/cas/CASState.cpp` | 6 / 6 | 100.0% | `██████████` | yes |
| `src/sims/cas/CASTarget.cpp` | 37 / 55 | 16.1% | `██░░░░░░░░` |  |
| `src/sims/cas/CASWidgets.cpp` | 7 / 9 | 65.8% | `███████░░░` |  |
| `src/sims/cas/Unk800230AC.cpp` | 4 / 6 | 60.4% | `██████░░░░` |  |
| `src/sims/cas/Unk80023D3C.cpp` | 4 / 5 | 27.8% | `███░░░░░░░` |  |

A file is linked from source once every function in it matches and its data is split out;
until then the build uses the original bytes for that file.

</details>

<!-- progress:end -->

Update this section after a build with `.venv/bin/python tools/readme_progress.py`.

## How it works

The project is based on [dtk-template](https://github.com/encounter/dtk-template).
The build splits the original `main.dol` into relocatable objects, swaps in
objects compiled from `src/` once they match, relinks, and verifies the result
is byte-identical to the original.

### Status

- The DOL is split into 293 objects and relinks to a byte-identical `main.dol`.
- So far the work has gone front to back through the game code; the engine is untouched.
- The disc has no symbol map. Names are carried over from The Sims 2
  (GameCube), which shares the engine and shipped with one: see
  `config/G4ME69/sims2_hints.txt` and `tools/align_sims2.py`.
- Compiler flags are `-O2 -G8 -fno-weak -frepo -fno-implement-inlines -fsigned-char`. The exact ProDG version is not pinned down:
  3.5 through 3.9.3 agree on everything matched so far, and 3.7 is the default.
- See `CLAUDE.md` for the layout of the binary and the working conventions.

## Building

Requirements: Python 3, `ninja`, `git`, `curl`, a C toolchain (for building
decomp-toolkit) and about 2 GB of disk. Everything else is downloaded into `build/`.

1. Put the disc image (ISO/RVZ/GCM...) in `orig/G4ME69/`.
2. Build the patched decomp-toolkit (see below): `tools/build_dtk.sh`
3. `python configure.py && ninja`

A successful build ends with `build/G4ME69/main.dol: OK`.

### Why a patched decomp-toolkit?

Upstream dtk (v1.8.3) assumes Metrowerks code generation and fails on this
binary. `tools/dtk-prodg.patch` teaches its relocation analysis that:

- GCC emits `lis`/`ori` only for integer constants (hashes, magic numbers),
  never for addresses, so those pairs must not become relocations outside of
  the hand-written startup code in `.init`.
- A `lis`/`ori` base followed by a displaced load/store (SN's hand-written
  debugger stub) must not have the displacement folded into the `ori`.
- Out-of-section targets (stack, small-data bases) reached with `lis`/`ori`
  are special symbols. Upstream crashes with a ~96 GB allocation here, so
  **do not run upstream dtk on this DOL without a memory limit**
  (`tools/dtk_safe.sh` wraps the patched binary with a 6 GiB cap).

`config/G4ME69/config.yml` additionally skips control-flow analysis for the
SN debugger stub and one function with an inline SN breakpoint (`.long 1`)
that hangs the analyzer.

### Linking

The DOL is linked with the original SN linker using
`config/G4ME69/ldscript.ld`. The Metrowerks linker can't reproduce the layout:
`.sdata2` is addressed through `r13`, and `.ctors` is a GCC-style
`-1, ..., 0` list.

## Third-party code

`libs/stlport` is STLport 4.5.3, unmodified (see `libs/stlport/README.STLport`
for its license). The game was built against it, and its templates have to be
compiled from the same source to match.

## Decompiling

- `build/G4ME69/asm/` holds the disassembly of every split object.
- `config/G4ME69/splits.txt` assigns address ranges to source files and
  `config/G4ME69/symbols.txt` names symbols. Translation units are separated
  by the static-initializer functions listed in `.ctors` (142 of them).
- Add the file to `configure.py` as `Object(NonMatching, "path.cpp")`, and
  switch it to `Matching` once the whole object matches.
- [objdiff](https://github.com/encounter/objdiff) works with the generated
  `objdiff.json`.

Helper scripts (run with the Python that has `capstone` installed):

- `tools/tu.sh src/file.cpp` compiles a source file and compares every function with the original.
- `tools/trycc.sh [-v VERSION] file.cpp [flags]` compiles a snippet with ProDG and prints its disassembly.
- `tools/fncmp.py OBJECT SYMBOL ADDR` compares a compiled function with the original, ignoring relocated fields.
- `tools/ppcdis.py ADDR [COUNT]` disassembles the original DOL.
- `tools/findref.py ADDR` finds references to an address.
- `tools/doldiff.py` compares the rebuilt DOL with the original section by section.

## Compiler notes

- `-O2`; `-O1` and `-O3` are ruled out.
- Virtual calls go through GCC 2.95 vtable entries of `{short delta; short index; void* pfn}`.
- `bool` is 4 bytes with this compiler.
