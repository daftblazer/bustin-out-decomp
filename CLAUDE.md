# The Sims: Bustin' Out (GameCube) decompilation

Matching decompilation of `G4ME69`. Read `README.md` for the build setup and why
the toolchain is unusual (SN ProDG / GCC 2.95.2, patched decomp-toolkit, `ngcld`).

## Commands

```sh
.venv/bin/python configure.py --ninja .venv/bin/ninja   # after editing configure.py / splits
.venv/bin/ninja                                         # must end with "main.dol: OK"
tools/tu.sh src/sims/ESimsApp.cpp [-v]                  # compile one file, compare every function
tools/trycc.sh [-v VERSION] file.cpp [flags]            # compile a scratch snippet, print asm
.venv/bin/python tools/sort_functions.py src/x/File.cpp # put a file's functions in address order
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

`tools/tu.sh` masks relocated fields, so it does **not** check the value of a float
constant or the text of a string: those live in `.rodata` and are only verified by
comparing the unit's data. Read constants from the original (`tools/ppcdis.py` won't
show them; unpack the bytes) rather than guessing. Float constants are pooled per
function, in order of first use, so each function has its own `0.0f`.

`tools/tu.sh` also rejects a function whose length differs from the original's
size in `symbols.txt`, so a short function can't pass by matching a prefix.

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

Compiler-generated functions (`__static_initialization_and_destruction_0`) have
the same name in every unit. Give each one that name in `symbols.txt` **with
`scope:local`**; without it the linker binds every unit's call to one copy and
`main.dol` no longer matches. Always run `ninja` before committing.

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

## STL and container templates

The game uses **STLport 4.5.3** (shipped with ProDG), vendored unmodified in
`libs/stlport`, on top of minimal C/C++ runtime headers in `libs/include`.
It is configured by the flags in `configure.py`: `_STLP_NO_OWN_IOSTREAMS`,
`_NOTHREADS`, `_STLP_NO_NEW_NEW_HEADER`. With these, `std::vector`, `std::deque`
and the node allocator compile to the original bytes; just `#include <vector>`.

Template instantiations are emitted after a unit's ordinary functions, in the
order they were first needed, followed by `__static_initialization_and_destruction_0`,
the unit's inline virtual functions, and `_GLOBAL_.I.<first function>`.
Getting that tail order right is a good check that the class definitions are right.

**Template repository.** Each template function exists only once in the whole
binary, as a global symbol in the first unit in link order that can provide it;
other units call that copy. The original build used GCC's template repository
(`-frepo`): the link step picked one object per instance and recompiled it with
the instance emitted. `tools/prodg_cc.py` reproduces this. It compiles with
`-frepo`, then marks as chosen exactly the offered instances whose mangled name
is a symbol inside the unit's ranges in `symbols.txt`, and recompiles.

So for a unit to emit a template function, two things are needed:

1. The function's symbol in `symbols.txt` must carry the exact mangled name
   (run `tools/tu.sh`; names it can't find are listed as "not in symbols.txt").
   The same goes for template static data such as
   `_Q24_STLt12__node_alloc2b0i0._S_free_list`.
2. The unit must *offer* the instance, i.e. some code or header it compiles
   uses that template with those arguments. A unit can hold instances its own
   functions never call, because another unit needed them.

Recognise template functions rather than decompiling them:

- `__node_alloc<false,0>`: `_M_allocate` (0x50), `_M_deallocate` (0x28),
  `_S_refill` (0xAC), `_S_chunk_alloc` (0x144). Blocks over 128 bytes go to
  `operator new` instead. Free list is `_S_free_list` in `.data`.
- `_Deque_base<T*>`: `_M_create_nodes` (0x4C), `_M_initialize_map` (0x104),
  `_M_destroy_nodes` (0x54), destructor (0x80).
- STLport containers keep a 4-byte allocator slot before the end-of-storage
  pointer: a `vector` is `{start, finish, <allocator>, end_of_storage}` (16 bytes).
- `EStream& operator>>(EStream&, TArray<T>&)` (`include/engine/EStream.h`, 0xAC)
  follows the `TArray` members it uses.
- `TArray<T, TArrayDefaultAllocator>` (`include/engine/TArray.h`) is the
  engine's own array, `{T* mData; int mSize; int mCapacity}`: `Init` (0x14),
  `Construct`/`Destruct` (0x1C each for trivial `T`; an empty counting loop),
  `Copy` (0x2C), `SetSize(int, int)` (0x10C).

Global `operator new` / `operator delete` are `__builtin_new` (0x801B8A3C) and
`__builtin_delete` (0x801B8A60). Exceptions and RTTI are off.

## Compiler notes (GCC 2.95.2, SN build)

- Flags: `-O2 -G8 -fno-weak -frepo -fno-implement-inlines -fsigned-char`. Without `-fno-implement-inlines` the file that defines a class's first non-inline virtual also emits out-of-line copies of all its inline members (stray `__dl__`, `__nw__`, inline constructors), which the original never has. Plain `char` is signed (reads of a
  `char` used in comparisons show `extsb`). `-fno-weak` is what puts vtables in `.rodata`
  and inline virtual functions in `.text`; `-frepo` handles templates (see above). `-O1` and `-O3` are ruled out (`-O3` moves inline functions
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
- A loop bound that shows up unfolded (`cmpwi r31, 4; blt` instead of `cmpwi r31, 3; ble`)
  came from an inline function, not a literal: `i < GetCount()` with
  `inline int GetCount() { return 4; }`.
- An extra `fmr`/`mr` into a second register for a clamped or selected value
  means the source used a separate result variable assigned in each branch
  (`if (v < lo) r = lo; else if (v > hi) r = hi; else r = v;`).
- A value read through a saved register after a call (`stfs f1, 4(r30)`) rather
  than straight off the stack was written through a reference in an inline function.
- A stray copy like `mr r0, r3; stw r0, field` after a call means the value was
  still needed in `r3`: typically a pointer converted to another type for the
  store while the original pointer is used as `this` for the next call
  (`T* p = new T; field = p; p->Method();`).
- Values reloaded from the stack right after being stored there (instead of
  reusing the registers) were read through a reference parameter of an inline
  function, e.g. an inline setter `void Set(const EVec3& v) { member = v; }`.
- `EVec3` copy construction is float by float, assignment is word by word, and
  `EVec3::Set(x, y, z)` stores x, then z, then y.
- Binding a returned object to a `const` reference (`const EVec3& p = Get();`) makes
  the compiler hold the temporary's address in a saved register from that point; a
  plain local copy does not. `EVec3::Normalize()` returns `EVec3&`.
- A destructor called with flag 0 is destroying a base class, 2 a member or local,
  3 a `delete`.
- An unsigned `switch` operand shows `cmplwi`/`blt` in the dispatch.
- The constructor table undercounts source files: a file with no static
  initializer leaves no entry, so a "unit" found that way can be two files. A
  second run of header strings in its `.rodata` is the tell.
- Absolute value in the original is a macro (`EABS` in `engine/EVec3.h`): both
  signs are compared explicitly. An inline function becomes one `fabs`.
- `rate = speed; if (!(diff > 0.0f)) rate = -rate;` and `if (diff <= 0.0f)` compile
  differently (`bgt` over the negate vs. a `cror`/`bns` pair).
- A temporary reuses the stack slot of a variable whose block has closed, so
  extra `{ }` around a short-lived local can be visible in the frame layout.
- Statement order matters: a run of constant stores comes out in a different
  order than written, with no simple rule. For three or four stores, compile
  every permutation in a scratch file and compare (see `TArray::Init`).
- Globals of 8 bytes or less are addressed through `r13`; bigger ones through
  `lis`/`addi`. Give placeholder types a realistic size.

## Commits

Single-line commit messages, no co-author or tool attribution.

- More source idioms (from the Create-A-Sim unit):
  - An extra `mr r4, r3` copying `this` before a call means `this` is an argument of that call, even when the
    callee ignores it (`viewer->fn(this)`).
  - `x = A` in one branch and `x = B` in another, written as separate member stores, come out as
    `li r0,A; b; li r0,B` plus one shared store (cross-jumping). Computing into a local first gives
    `subfic/adde` instead.
  - `if (p) { delete p; p = 0; }` and `if (p) { delete p; } p = 0;` differ only in whether the null branch
    skips the store; check the branch target.
  - A matrix copied as pairs `lwz r9/r10 ... stw r9/r10` is an inline copy through `unsigned long long`
    (`EMat4::Copy64`), not the default assignment.
  - Compiler-generated `operator=` copies scalar arrays with a `bdnz` loop, class-type arrays with a
    count-down `cmpwi/addi -1/bne` loop, and skips the vtable pointer; the skipped word locates the vptr.
    Such an operator is emitted out of line once it exceeds the implicit inline size limit.
  - A class derived from one with virtuals that adds no destructor of its own is destroyed by calling the
    base destructor directly with flag 0 and no vtable store.
  - A look-up helper used inside `new T(Get("a"), ..., Get("b"))` runs after `__builtin_new` and before the
    constructor; write it as an inline function, not as locals ahead of the `new`.
  - `tools/gen_fields.py Class.fields` generates padded member lists for large, partly known classes.
  - A call whose object pointer is loaded from a member *after* the other arguments are set up
    (`lis r4; lwz r3,off(r31); addi r4`) goes through an inline forwarding member
    (`int Find(const char* n) { return fn_801800FC(n); }`); a direct call loads `this` first. This does
    not explain every late-`r3` case (see fn_800102B0).
  - Accessing a member object's field through an inline setter keeps the object's address register
    (`stfs f0,0x54(r25)`); direct access folds the offset into `this` (`stfs f0,0x4f44(r31)`).
  - An inline function with a constant float argument keeps its multiplication unfolded
    (`EDegToRad(175.0f)` is two loads and an `fmuls`).
  - Runs of zero stores of mixed width: when a byte store uses its own zero register (`li r11,0`) but the
    original shares one, a word-sized zero store comes first in the source. In fn_8000D440 the source
    order `unk458C, unk4590, unk45C9` is emitted as `45c9, 458c, 4590`; try moving byte stores last.
  - `EVec2` has a user-defined copy constructor like `EVec3`. Besides float-wise copies, that makes
    every `EVec2` local live in memory from its declaration, so locals get stack slots in declaration
    order (lowest first). If a small struct's slots come out above later locals, its type is missing a
    user copy constructor. The text-extent function (0x8003D550) returns `EVec2`.
  - The text-drawing call (0x8003D740) takes its position **by value**: write `EVec2 at(x, y); font->Draw(..., at, ...)`
    (a named local, copied into the argument slot). A temporary built in the call omits the copy and is shorter
    than the original. The sprite call (ERC slot 49) takes `const EVec2&` positions, so there temporaries are right
    and their slots swap between consecutive calls.
  - A string look-up written out (`Result r = global.Find("x"); v = r.ptr ? *r.ptr : 0;`) loads the global's
    address before the string's; through the inline `GetText("x")` the string comes first. Both occur.
  - Several destructors that all store the *same* vtable at the end of a file are the inline destructor of a
    base class emitted once per derived class (each derived class's implicit destructor).
  - A loop counter reused by two consecutive loops (same register) is one variable declared before both.
  - `EColorF` (four floats) also has a user-defined float-wise copy constructor; assignment is word-wise.
  - When an argument expression has a branch (`p ? *p : 0`) and another argument is a by-value object,
    the original evaluates the branchy one first: put it in a local before the call.
  - `EMat4::SetPos(EVec3(x, y, z))` writes a temporary and then copies it float by float into row 3
    (placement-new copy construction), like `SetRow3`.
  - Indexed loads `lwzx rD, rBase, rIndex` with the array pointer first come from an inline accessor
    (`T& At(int i) { return data[i]; }`); plain `data[i]` puts the index register first.
  - Two calls on the same member pointer that reload it between them (`lwz r3, off(r30)` twice) are two
    statements; nesting one call inside the other's arguments caches the pointer in a saved register.
  - `if (flag) { if (x != 1) continue; } else { if (x != 0) continue; }` gives `cmpwi 1; b; cmpwi 0; bne`
    (the branches merge); `flag ? x == 1 : x == 0` keeps two separate branches.
  - A bit test whose mask is computed before a call (`li r30,1; slw` ... `and.`) needs the mask in a local;
    written inline it becomes a shift of the tested value and `andi. 1`.
