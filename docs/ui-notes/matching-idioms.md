# Matching idioms for the Apt UI library (-O0, ProDG GCC 2.95)

Found while matching `src/ui/Unk8012F420.cpp` and `src/ui/Unk8013C054.cpp`. They apply to any unit of this library.

## Trailing branches

At -O0 this compiler ends many functions with unreachable `b` instructions to the epilogue. How many depends on how the
source ends **and on compiler state left behind by earlier functions in the same file**, so keep functions in address order
and match them in that order (the right idiom can change when an earlier function changes).

Try these in order for a function that is only a few `b` instructions off:

| Source ending | Typical effect |
|---|---|
| `return x;` | one `b` |
| `if (1) { return x; }` | `b; b; b` (state A) |
| `do { return x; } while (0);` | `b; b; b` (state B, e.g. after functions returning a plain variable), five in state A |
| `return x; do { } while (0);` | `b; b; b` for a returned `register` local (`r`) |
| `return x; return x;` | a second copy of the return value move: usually wrong |
| void: `...; return;` / `return; return;` | one / two extra `b` |

`tools/` has no helper for this; the loop used was: compile with `tools/tu0.sh` (or `tu_ui.sh`), and for each function that
differs only in instruction count, rewrite its ending with the next idiom and recompile.

## Other findings

- A function that leaves its pointer argument untouched and in `r3` (`mr r0,r3; mr r3,r0`) is a **member returning `this`**; a free
  function spills its argument.
- A destructor called with flag 0 inside a hand-written release: declare the callee with the symbol as an `asm` label and call it
  as a plain function; a C++ destructor call passes 2. (`fn_8012F564`)
- A struct member assigned from an expression that also reads it, `*&h->off.v = p + h->off.v`, computes the address first.
- Globals of 8 bytes or less are addressed through `r13`; to get `lis`/`lwz` declare the extern as an array of 4 words.
- `names[i] = names[--count]` keeps the destination address ahead of the decrement; two statements do not.
