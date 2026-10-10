# 2D drawn at a world position (thought bubbles, anything projected from 3D)

Findings for the recomp's widescreen layer. All addresses are the original DOL's.
Not decompiled to matching source: read from the disassembly, so field meanings marked "not confirmed" are guesses.

## The projection call: `E3DWindow::TransformToScreen(EVec3* in, EVec2* out)` = `0x80156130` (0xC4 bytes)

Returns a bool (1 = in front of the camera, 0 = behind). Callers: `fn_80007470` (ESimsCam, 0x800074C4),
`fn_80060F94` (0x80061210) and `fn_80066678` (0x800666BC).

```
clip = Transform4(this + 0x120, (in.x, in.y, in.z, 1.0))      // 0x801B27E0; the combined view*projection
if (clip.w <= 0.0) return 0                                  // w is the float at r1+0x14, tested against 0.0 (0x802B7B90)
inv = 1.0 / clip.w
out[i] = clip[i] * inv * scale[i] + offset[i]   for i = 0, 1    // scale = this+0x200 (x, y, z), offset = this+0x210
return 1
```

So `out` is in **frame-buffer pixels** (GX viewport style), not in normalised coordinates.

## Where `scale` and `offset` come from

`E3DWindow` keeps its rectangle twice:

- `+0x1E0..+0x1EC`: the rectangle as fractions of the window (`x0, y0, x1, y1`).
- `+0x1F0..+0x1FC`: the same rectangle in pixels: `frac * size + origin`, where `size` is `this+0x00/+0x14`
  (width, height) and `origin` is `this+0x30/+0x34` (`0x80154848`, set by `0x80154840`; the inverse is `0x801548A0`).

`0x80154970` then calls `0x801627E4(manager, this+0x200, this+0x1F0)` and `0x801627E4(manager, this+0x220, this+0x1E0)`.
`manager` is `lbl_8037C198` (`-0x7248(r13)`, the application object). `0x801627E4` builds a viewport transform:

```
scale  = ( (x1 - x0) * 0.5, -(y1 - y0) * 0.5, <z range> )   // y is negated
offset = ( x0 + 0.5*(x1-x0) , y0 + 0.5*(y1-y0), <z near> )  // constants at 0x802B8FBC.. (0.5, 1.0, 0.0, 0.5)
```

The two virtual calls at slots `0x118/0x11C` and `0x120/0x124` of the manager are the depth range.
The pixel rectangle at `+0x1F0` is relative to the 640x480 frame buffer, so a point in front of a full-screen camera
comes out with `x` in 0..640 and `y` in 0..480.

## What this means for widescreen

The recomp widens the camera's aspect ratio (`fn_80154490`, `SetProjection`) and then stretches the 640-wide
frame buffer to the display. A point's `x` from `TransformToScreen` is therefore correct **in frame-buffer
space**: displayed at `c + (x - c) * k` after the stretch (`c` = 320, `k` = display aspect / (4/3)).

The 2D layer narrows each sprite by `1/k` about the centre so it is not stretched, which puts a sprite
drawn at frame-buffer `x` at displayed `c + (x - c)` -- i.e. as if the view were still 4:3. That is the drift
toward the centre seen on thought bubbles and similar.

Suggested fix, at the source rather than in the 2D layer: hook the end of `0x80156130` (the store loop at
`0x801561B0`-`0x801561CC` writes `out[0]` and `out[1]`; the return is at `0x801561DC`) and, when it returns 1,
replace `out[0]` with `c + (out[0] - c) * k`, where `c` is the window's own centre (`this+0x1F0 .. +0x1F8` midpoint),
not necessarily 320 for split-screen. The sprite then lands at the right displayed place after the 2D
layer's narrowing. Check the three callers for clamping against 0..640 afterwards (a value outside the frame
buffer may be clamped or culled by the caller).

Only the callers above use this function, so the change is local.

## Related E3DWindow offsets (from `0x80154490`, `0x801545A8`, `0x80155DFC`)

| Offset | Meaning |
|---|---|
| `0x000` | window width (float), `0x014` height, `0x030/0x034` pixel origin |
| `0x060/0x064` | read by `0x80154970` (meaning not confirmed) |
| `0x120` | view*projection matrix (4x4) used by `TransformToScreen` |
| `0x160` | projection matrix (copied from the builder at `0x801B3908` / `0x801B3834`) |
| `0x1A0, 0x1B0, 0x1C0, 0x1D0` | copy of the projection matrix plus three outputs of `0x801B3B60`; set by `ProjectionMatrixChanged` (`0x80155DFC`). Purpose not confirmed |
| `0x1E0` / `0x1F0` | window rectangle, fractions / pixels |
| `0x200` / `0x210` | viewport scale / offset (three floats each) |
| `0x220` | second viewport pair for the fractional rectangle |
| `0x24C` | stored by both `SetProjection` and `SetOrthoProjection` (`0x801545A8`) from a constant; meaning not confirmed |
| `0x25C` | set from the aspect argument in `SetProjection`; in `SetOrthoProjection` from (right-left)/(top-bottom)-style quotient |
| `0x2B0`-`0x2B8` | near, far |
