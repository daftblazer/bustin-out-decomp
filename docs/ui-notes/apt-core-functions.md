# Apt core functions matched in `src/ui/Unk8012F420.cpp` (0x8012F420-0x801352FC)

Facts from these functions that matter for the recomp. Everything else in the file is value-class boilerplate
(constructors, allocators, per-type release and delete functions, type tests) with no screen-space meaning.

## Affine transform of a point: `0x8013071C(in, m, out)`

`m` is the movie's 2x3 matrix `{a, b, c, d, tx, ty}` as six floats (the same layout as the display-object matrix at `obj+0x0C`):

```
out.x = a * in.x + c * in.y + tx
out.y = b * in.x + d * in.y + ty
```

Every position the interpreter computes from a matrix goes through this form, so a widescreen change that scales `a` and `tx`
of the root matrix scales every point derived from it.

## Button event mask to clip event flags: `0x8012FF4C(mask)`

| Mask bit | Clip event flag | Event |
|---|---|---|
| `0x04` | `0x400` | press |
| `0x08` | `0x800` | release |
| `0x40` | `0x1000` | release outside |
| `0x01` | `0x2000` | roll over |
| `0x02` | `0x4000` | roll out |
| `0x20` | `0x8000` | drag over |
| `0x10` | `0x10000` | drag out |

## Queued events: `0x80131E04` runs and clears the queue; `0x80131D08` decodes one

The player context (`lbl_8037D0F4`, 0x3F3C bytes) keeps up to N events at `+0x3E28` and their count at `+0x3E24`.
An event word's low two bits are its kind. Kind 0 goes to `0x80131010`. Kind 1 packs three fields:
bits 17-31 (15 bits), bits 10-16 (7 bits) and bits 2-9 (8 bits); the first two plus the word go to `0x801312E0`, then
`0x80131630` fills two out values, and when the second is zero `0x80131A10` runs with the first.
(The meaning of the fields is not known yet; the mouse position set by `fn_8012BA5C` is the likely producer.)

## Apt value to integer: `0x801321E4`

Strings go through the C library's number parser, types 5 and 7 return the word at `+4`, type 6 (float) is truncated,
undefined and every other type give 0.

## Shutdown: `0x80132D9C`

Releases the shared values (the "undefined" value at `lbl_8037D110`, and the seven other globals in `lbl_8037D108`-`lbl_8037D12C`)
and clears the player. Nothing in it touches layout.
