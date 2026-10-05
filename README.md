The Sims: Bustin' Out (GameCube) decompilation
==============================================

A work-in-progress matching decompilation of *The Sims: Bustin' Out* for GameCube.

| | |
|---|---|
| Version | USA, `G4ME69`, revision 0 (`NGC Sims Bustin Out Build 2.1.3.31-1i`) |
| `main.dol` SHA-1 | `26f0bf319a5fd3ea3d3d86e6117fbc78e259231c` |
| Engine | Edge of Reality "EOR Engine v2.0" (built Nov 13 2003) |
| Toolchain | SN Systems ProDG for GameCube (`ngccc`, GCC 2.95.2) and `ngcld`, **not** Metrowerks |

The project is based on [dtk-template](https://github.com/encounter/dtk-template).
The build splits the original `main.dol` into relocatable objects, swaps in
objects compiled from `src/` once they match, relinks, and verifies the result
is byte-identical to the original.

No game assets or code from the disc are included. You need your own copy.

Status
------

- The DOL is split into 293 objects and relinks to a byte-identical `main.dol`.
- 160 of 10,848 functions are decompiled (`python configure.py progress`).
- The disc has no symbol map. Names are carried over from The Sims 2
  (GameCube), which shares the engine and shipped with one: see
  `config/G4ME69/sims2_hints.txt` and `tools/align_sims2.py`.
- Compiler flags are `-O2 -G8 -fno-weak -frepo -fno-implement-inlines -fsigned-char`. The exact ProDG version is not pinned down:
  3.5 through 3.9.3 agree on everything matched so far, and 3.7 is the default.
- See `CLAUDE.md` for the layout of the binary and the working conventions.

Building
--------

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

Third-party code
----------------

`libs/stlport` is STLport 4.5.3, unmodified (see `libs/stlport/README.STLport`
for its license). The game was built against it, and its templates have to be
compiled from the same source to match.

Decompiling
-----------

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

Compiler notes
--------------

- `-O2`; `-O1` and `-O3` are ruled out.
- Virtual calls go through GCC 2.95 vtable entries of `{short delta; short index; void* pfn}`.
- `bool` is 4 bytes with this compiler.
