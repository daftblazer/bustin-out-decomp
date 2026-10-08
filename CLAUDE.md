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
  - A string object rebuilt in the *same* stack slot for each of several look-ups, with the result
    stored only after the string's destructor, is an inline helper that owns the string as a local
    (`T* Find(list, name, suffix) { String key(name, suffix); return table->Get(list, key); }`).
    Temporaries written at each call site get a fresh slot each and store before destroying.
  - A local object whose address sits in a saved register for a whole function is a temporary bound
    to a `const T&` parameter (`Use(String("AM"))`), not a named local.
  - Giving placement `operator new` an empty `throw()` makes the compiler null-check its result; that
    breaks `EMat4::SetRow3` users, so leave it without one.
  - A run of constant stores to consecutive members written in natural order is emitted with the *last*
    statement first and the rest in order (`a=0; b=0; c=0;` gives `c, a, b`). Try the natural order before
    permuting (the `CASSkin` constructor and reset function match this way).
  - `lis rN,1; addic. rN,-1; bne` followed by an explicit `li rN,0` for the next loop is a count-*up* loop
    (`for (i = 0; i < 0x10000; i++)`) that the compiler reversed. Written as a countdown, the compiler knows
    the counter ends at zero and drops the `li`.
  - A fill loop whose value sits in its own register before the pointer set-up has the value in a local
    (`signed char one = 1; ... *p-- = one;`).
  - Two `switch` cases with identical bodies written out separately keep separate tests
    (`cmpwi 5; beq; blt; cmpwi 6; beq`); `case 5: case 6:` becomes a range test.
  - `fmr` copies of float values feeding an `fdiv` mean the source kept `double` copies of float locals
    (`double sum = lo + hi; double ddelta = delta;`).
  - `rlwinm rD,rS,3,0x18,0x1c` on a byte is `(v & 0x1F) << 3`; `(v << 3) & 0xF8` stored to a byte loses the mask.
  - Float constants are pooled in order of first appearance in the *source*, so `x * 0.2f + 0.0f` with the
    pool order `0.0, 0.2` had the constants in named locals declared in that order (`float lo = 0.0f; float hi = 0.2f;`).
  - A colour whose four equal components are stored alpha first is `EColorF(float)` (`r = g = b = a = value`),
    not the four-argument constructor.
  - An inline predicate returning `bool` that is used in an `if` leaves `mfcr`/`rlwinm`; compare through
    inline accessors that return the floats instead.
  - A class with a non-inline virtual declared (its key function lives in another unit) does not get its inline
    destructor or vtable emitted here; a derived destructor then stores the base vtable itself and passes its own
    flag on to the next non-inline base destructor.
  - The unit splits by constructor-table entry can hide two files (see above); the unit at 0x800230AC is
    `Unk800230AC.cpp` + `Unk80023D3C.cpp`, with the second run of header strings at 0x802961E0.
  - Including `sims/ESimsApp.h` after `sims/cas/CASSim.h` makes the compiler write an empty object with no
    message. Check the size of `build/try/*.o` when `tools/tu.sh` prints nothing.
  - Names from the header strings of the skin-texture unit: the layer images are `ERRleTexture`
    (`games/sims/ESrc/e_rrletexture.h`), the "material" is `EShader`; placeholders are not renamed yet.

## Linking a unit from source

Switching a unit to `Matching` needs more than matching functions (see `sims/Unk800052C8.cpp`, `sims/cas/CASState.cpp`):

- Every function the unit calls needs its mangled name in `symbols.txt`. A missing one makes `ngcld` exit 99 with no message.
- The run of class-name strings at the start of a unit's `.rodata` comes from unused inline functions in the engine headers,
  in include order. The stand-ins are `include/engine/e_*.h` and `include/sims/e_*.h`; include them in the order the strings appear.
- The engine build string carries the compile time of each file (`#define EOR_BUILD_TIME "21:41:26"` before
  `engine/e_engine.h`). It goes up file by file, so it also tells source files apart inside one constructor-table "unit":
  the unit after `Unk80026864` is five files (21:41:24, :26, :26, :27, :28).
- Objects built from source carry an empty `.sbss2`; `ldscript.ld` folds it into `.sbss`.
- A file that defines a class twice through two header sets (or includes `sims/ESimsApp.h` after `sims/cas/CASSim.h`) can
  come out as an empty ~800-byte object with no error from `tools/tu.sh`. Compile it directly and add the includes one at a time.

- More source idioms (cheats, cursor screen and build tools):
  - `EVec2(float v)` sets `x = y = v` (y is stored first); `EVec2(0.0f)` is the zero vector in constructors.
  - `EVec2::Normalize()` returns `EVec2&` and is called on temporaries: `EVec2 dir((*to - *from).Normalize());` puts the
    temporary above `dir` on the stack and copies it float by float. Operand order of the scalar product is visible:
    `step * v` gives `fmuls f, step, v.x`, `v * step` the reverse.
  - A table of pointers to member functions is filled in source order (mostly); a pointer to member is null-tested by its
    index word. The constants sit in `.rodata` as `{delta, index, pfn}` and look like a small vtable.
  - The screens derive from `UnkTargetBase` and virtually from `Unk802A2AC0` (mode word + three virtuals): constructors take
    an in-charge flag (`__11Classii`), the virtual base pointer is at 0x48.
  - `x < 0 ? 2 : 3` emits `li 3; bge; li 2`; `x >= 0 ? 3 : 2` the other way round.
  - Two `return` statements with the same expression in an `if`/`else` keep both copies of the code; one shared
    `return` after a variable assigned in each branch merges them.
  - Pointers that are reloaded before every use (`lwz r3, 0xc(r29)` each time) were not cached in a local: write
    `((T*)unkC)->f()` at each use. The same goes for `lbl_802E6700.unkBC`.
  - `bool r = cond ? InlineA() : InlineB(); if (!r)` costs an extra `mr`; testing the conditional expression directly does not.
  - STLport iterators live in memory (they have a copy constructor). A tree walk that keeps the node in a register was
    written with the node pointer and `_STL::_Rb_global<bool>::_M_increment` directly (see `fn_80038014`).
  - A global declared with a placeholder type smaller than 8 bytes is addressed through `r13` even when the real object is
    large; give `extern` placeholders their real size (`lbl_802F7658`).
  - A function whose every path ends in `li r3, N` but one path computes through `r0` first (`nor r0; srwi r3, r0`)
    has a single result variable assigned in an `if`/`else if` chain and one `return result;` (`fn_800369A0`).
  - `!(flags & 1)` in a condition can come out as `xori; andi.`; `(flags & 1) == 0` gives the plain `andi.; bne`.
  - Two `rlwinm` in a row clearing different bits are two statements (`f &= ~1; f &= ~4;`); one expression
    `(f & ~1) & ~4` folds into `li r9, -6; and`.
  - Cross-jumping never merges a call site into the code that falls off the end of the function (checked in a
    scratch file). If the original's shared tail is the last call, something followed it in the source.
  - Releasing a resource is a statement macro wrapped in `do { } while (0)`
    (`do { if (p) { fn_801767FC(p); p = 0; } } while (0)`). The loop note it leaves keeps the first load of the
    pointer behind the stores that precede it, and changes how the last call before it is scheduled. Several
    destructors and reset functions only match this way (`fn_800318B0`, `fn_80033BAC`); try it wherever a release
    block's first load comes "too early". The copies in the build-tool files (`E_RELEASE_RESOURCE`,
    `UNK_RELEASE_801767FC`) should become one shared macro.
  - Whether a callee returns a value changes the order its arguments are loaded in, even when the result is
    ignored: declared `int fn(int id, bool on)` the second argument is loaded first, declared `void` the first.
    The same holds for members: an `operator=` or setter that returns a reference loads its arguments before `this`.
    When only the argument order of a call differs, change the callee's return type before anything else.
  - A function returning `char` adds `extsb r3, r3` before the return; none means `unsigned char`.
  - A class modelled as a chain of placeholder structs inheriting one destructor does not behave like the real
    class: with its own destructor declared, temporaries of it are placed and destroyed differently. Likewise a
    "derived" placeholder with an implicit inline destructor keeps the object's address in a register;
    0x801C6F44 is a constructor of `Unk801C6F20` itself, not of a derived class.
  - Minimum and maximum of converted ints are macros (`((a) < (b) ? (a) : (b))`): the int-to-float conversion is
    evaluated again for each use, which an inline function would not do.
  - An inline `int Round(float v) { return (int)(v + 0.5f); }` loads the 0.5 before the value; written out, the
    value comes first. An inline linear blend keeps its constant arguments unfolded.
  - `EVec2` has an indexing operator (a store through it keeps the component's address in a register) and can be
    built from an `EVec3` (first two components). Sub-tile coordinates are set y first.
  - Assigning the same value in both branches of an `if`/`else` (`handle = texture->unk4;` in each) reproduces
    code where a load is duplicated into both arms; it usually stands for an inline accessor used in each arm.

## Storable classes (EStorable / EResource)

`include/engine/EStorable.h` has the base classes and `E_STORABLE_BODY`, the members every storable class
defines; `sims/ERFont.cpp` is the first unit built on it. What the tail of such a unit looks like and why:

- After the static initialiser come, in this order: the three functions that create an instance, create one
  in place and destroy one; the inline virtuals (`Delete`, `GetClass`, three record accessors); a local
  `__builtin_new` (li r4,0x10; bl 0x80169F1C) and a local `__nw__FUiPv`; the `_GLOBAL_.I` thunk.
- The three creation functions are **friends defined in the class body**. Static members with the same bodies
  are not emitted at all under `-fno-implement-inlines` when the class has a key function (they stay undefined).
- `operator new` and placement new are **global inline operators defined after the class**
  (`include/engine/ENew.h`, included last). Defined later than their first use, they are called out of line and
  the unit gets local copies named `__builtin_new` and `__nw__FUiPv`; both need `scope:local` in `symbols.txt`.
- The static initialiser registers the class with `fn_801BBFCC(&record, create, createAt, destroy, 0, "Name",
  &parentRecord)` and stores the result. The class record is in `.bss` far from the unit's other data.
- The vtable pointer of a storable class is at offset 0 (`EStorable` has no data members).
- A resource manager is a class derived from `EResourceManager` (`include/engine/EResourceManager.h`, vtable
  pointer at 0xA0) that overrides `GetHeap` and `AllocateAndLoadResource`; the resource's `operator new`
  allocates from its manager and passes `__FILE__`, `__LINE__` and a name, which is where a header's file-name
  string comes from.
- A global object of a class with a destructor is constructed by the static initialiser but never destroyed in
  the original (no destruction branch, no `_GLOBAL_.D`); every compiler version here emits both. Unsolved, in
  `sims/ECheats.cpp` and `sims/Unk8003DE78.cpp`.

- More source idioms (font and panel units):
  - Three or more zero stores to members written in natural order come out with the last statement first
    (again): write them in member order and check, before permuting.
  - A colour set with alpha stored first and red last is `r = g = b = a = value` on the member itself (through
    an inline setter), not an assignment from a temporary.
  - `if (x == 0) return &obj; return 0;` gives `li r3,0; bnelr; lis r3; addi r3`; the conditional expression
    and the result-variable forms are one instruction longer.
  - An object reloaded from the stack at every use (`lwz r11, 8(r1)`) with a dead `p = 0` store at the end of
    its scope is a small handle class with a destructor; a plain pointer stays in a register.
  - `lbz` passed to a constructor without `extsb` means the parameter is `unsigned char`.
  - A function returning 0, 1 or 2 as `li r3, 0; li r4, N` returns `long long`.
  - A header-string run with no functions and no data after it is a source file that contributed nothing but
    its headers' strings (the second file of unit 0x8003B870).
  - A callee that returns a reference (`EFile& operator>>(EFile&, int&)`) has its second argument loaded first.
  - An array indexed with the base register first (`lwzx r11, r9, r8`) is read through an inline accessor
    (`EFontPage*& Page(int i)`); see the earlier note on `At(i)`.

