# The Sims: Bustin' Out (GameCube) decompilation

Matching decompilation of `G4ME69`. Read `README.md` for the build setup and why
the toolchain is unusual (SN ProDG / GCC 2.95.2, patched decomp-toolkit, `ngcld`).

## Commands

```sh
.venv/bin/python configure.py --ninja .venv/bin/ninja   # after editing configure.py / splits
.venv/bin/ninja                                         # must end with "main.dol: OK"
tools/tu.sh src/sims/ESimsApp.cpp [-v]                  # compile one file, compare every function
tools/trycc.sh [-v VERSION] file.cpp [flags]            # compile a scratch snippet, print asm
.venv/bin/python tools/ppcdis.py ADDR [COUNT]           # disassemble the original
.venv/bin/python tools/findref.py ADDR                  # who references an address
```

- Always use `.venv/bin/python` (it has `ninja` and `capstone`).
- Never run upstream `dtk` on this DOL; use `tools/dtk_safe.sh` (memory-capped).
  Wrap anything unproven in `ulimit -v`. An uncapped run once took the machine down.
- Disassembly of every object is in `build/G4ME69/asm/` after a build.

## What counts as matched

A function is matched only when hand-written C/C++ compiles to the original
bytes (`tools/tu.sh` prints `MATCH`). No inline asm, no byte arrays, no
post-processing of compiler output. If a function can't be matched, leave the
best attempt in place with a `// NON_MATCHING: <what differs>` comment and move on.

`ngcld` resolves undefined symbols to 0 without an error, so only the final
`main.dol: OK` proves a link is right.

## Layout of the binary

Function prologue style separates the compilers cleanly:

| Range | Compiler | Contents |
|---|---|---|
| `800034A0`-`801098DC` | GCC | Game code (`sims/`), C++ |
| `80109968`-`8010C7FF` | hand asm / MW style | `libsn` (SN debugger stub) |
| `8010C824`-`80117FD4` | GCC | C library and runtime |
| `80118124`-`8012AAC0` | Metrowerks | Dolphin SDK: OS, EXI, SI, DVD, VI, PAD, AI |
| `8012AD10`-`80151F80` | GCC | C libraries without static initializers (unidentified) |
| `80152074`-`80153B34` | Metrowerks | Dolphin SDK: GBA |
| `80153C2C`-`8026FE50` | GCC | EOR engine (`engine/`), C++ |
| `80270064`-`8028FF48` | Metrowerks | Dolphin SDK: THP, AR, ARQ, AX, DSP, CARD, GX |
| `8028FF78`-`80291A7C` | GCC | VM library, misc |

Do not hand-decompile the Metrowerks ranges with ProDG: that code needs `mwcceppc`
and is better taken from existing Dolphin SDK decompilations.

## Names

The disc has no symbols. Sources of real names, best first:

1. `config/G4ME69/sims2_hints.txt`: names carried over from The Sims 2 (GameCube),
   which shares the engine and shipped with a symbol map. `=` lines have an
   identical function size (reliable); `~` lines are positional guesses.
   Regenerate with
   `tools/align_sims2.py reference/sims2_symbols.txt`. Even where a function has no hint,
   the Sims 2 symbol list (`reference/sims2_symbols.txt`) is worth reading: classes keep their method order
   (`ESimsApp`, `EApp`, `PlayerCheats`, ...).
2. Class-name strings in `.rodata` (`EStorable`, `EResource`, `EInstance`, ...).
3. Otherwise keep `fn_XXXXXXXX` / `lbl_XXXXXXXX` / `unkNNN` (offset in hex).
   Don't invent descriptive names without evidence.

When a function is decompiled, rename its entry in `config/G4ME69/symbols.txt`
to the GCC 2.95 mangled name the compiler emits (`tools/rename.py OLD NEW`):
`Method__5Classi`, constructor `__5Class`, destructor `_._5Class`.

## Source layout

- `src/sims/` game code, `src/engine/` engine code; headers mirror this under `include/`.
- One class per header. Shared engine classes go in `include/engine/` so every
  file uses the same layout; check there before declaring a class.
- A new source file needs a range in `config/G4ME69/splits.txt` and an
  `Object(NonMatching, ...)` entry in `configure.py`. Translation units end at
  the static-initializer functions listed in `.ctors`.

## Splitting a unit's data

A unit can only be switched to `Matching` once its data sections are split too.

1. `.venv/bin/python tools/tu_data.py -n 20` lists, per unit in link order, the
   range of data referenced by that unit alone. Add a unit name to list the symbols.
2. Units keep the same order in every section. A unit's range runs from the
   previous unit's end to the next unit's first exclusive symbol; outliers far
   from the rest are shared globals owned by another unit.
3. `.rodata` of a C++ unit is: strings and constants from headers, the unit's
   own strings and floats, then its vtables. Many units start with the same
   run of class-name strings (`EStorable`, `EResource`, ...), which marks the boundary.
4. Add the ranges to `splits.txt`. If dtk reports that a split "ends within
   symbol", the guessed size of that symbol in `symbols.txt` is too large: fix
   it (vtables are `_vt.<mangled class>`, 8 bytes per slot).
5. Rebuild; `main.dol: OK` confirms the split is consistent.

Inline member functions are emitted at the end of the object in declaration
order, so the order of declarations in a class body is observable.

## Compiler notes (GCC 2.95.2, SN build)

- Flags: `-O2 -G8 -fno-weak -fsigned-char`. Plain `char` is signed (reads of a
  `char` used in comparisons show `extsb`). `-fno-weak` is what puts vtables in `.rodata` and
  gives every translation unit its own local copy of inline and template
  functions (so identical STL helpers appear many times in the binary). `-O1` and `-O3` are ruled out (`-O3` moves inline functions
  to the front of the object; the original has them at the end).
- The exact ProDG version is unknown: 3.5 through 3.9.3 agree on everything
  matched so far. Note any function where they differ.
- The vtable pointer is placed after the data members of the class that first
  declares a virtual function, not at offset 0.
- Vtable entries are 8 bytes: `{short delta; short index; void* pfn}`. Slot 0 is
  empty (RTTI is off), so the first virtual is at `+8`.
- Destructors take a hidden `int` flag (`delete p` passes 3).
- `bool` is 4 bytes; a byte-sized flag is `char`/`unsigned char`.
- GCC uses `lis`/`ori` only for integer constants and `lis`/`addi` for addresses.
- Statement order matters: the scheduler tends to hoist the last of a run of
  constant stores to the front, so try rotating assignments.
- Globals of 8 bytes or less are addressed through `r13`; bigger ones through
  `lis`/`addi`. Give placeholder types a realistic size.

## Commits

Single-line commit messages, no co-author or tool attribution.
