# Read-only data status of the NonMatching source files

Each file is compiled with `tools/tu.sh` and its `.rodata` (`build/try/<name>.o`) is compared with
the original split object (`build/G4ME69/obj/<path>.o`) using `objcopy -O binary -j .rodata` and a
byte comparison. Nothing here was fixed; this is a snapshot of the state at the commit that added it.

| File | Result | Mine (bytes) | Original (bytes) | First differing offset |
|---|---|---:|---:|---|
| `src/sims/ESimsApp.cpp` | sizes differ | 1352 | 1368 | 0x1D9 |
| `src/sims/ESimsCam.cpp` | sizes differ | 432 | 1376 | 0x0 |
| `src/sims/cas/CASWidgets.cpp` | sizes differ | 392 | 1112 | 0x0 |
| `src/sims/cas/CASTarget.cpp` | sizes differ | 3112 | 4000 | 0x0 |
| `src/sims/cas/CASSelectors.cpp` | sizes differ | 1360 | 1856 | 0x0 |
| `src/sims/cas/CASSim.cpp` | sizes differ | 2536 | 3712 | 0x0 |
| `src/sims/cas/CASSkin.cpp` | sizes differ | 1184 | 1344 | 0x0 |
| `src/sims/cas/Unk800230AC.cpp` | sizes differ | 848 | 1216 | 0x0 |
| `src/sims/cas/Unk80023D3C.cpp` | sizes differ | 752 | 592 | 0x0 |
| `src/sims/ECheats.cpp` | identical | 1200 | 1200 | - |
| `src/sims/Unk80026864.cpp` | sizes differ | 560 | 1656 | 0x0 |
| `src/sims/Unk8002EFAC.cpp` | sizes differ | 464 | 592 | 0x16C |
| `src/sims/Unk800315FC.cpp` | sizes differ | 504 | 520 | 0x1AC |
| `src/sims/Unk80033974.cpp` | sizes differ | 664 | 704 | 0x154 |
| `src/sims/Unk80039E78.cpp` | sizes differ | 504 | 520 | 0x1C8 |
| `src/sims/Unk8003AA6C.cpp` | sizes differ | 1152 | 1184 | 0x458 |
| `src/sims/Unk8003B870.cpp` | sizes differ | 328 | 408 | 0x110 |
| `src/sims/ERFont.cpp` | identical | 520 | 520 | - |
| `src/sims/ESimsDataManager.cpp` | identical | 1320 | 1320 | - |
| `src/sims/Unk800401FC.cpp` | identical | 2264 | 2264 | - |
| `src/sims/Unk800454AC.cpp` | sizes differ | 1160 | 1848 | 0x2EC |
| `src/sims/Unk80049ADC.cpp` | sizes differ | 1340 | 1560 | 0x4FA |

## Reading the table

- **identical** (4 files): the data is complete and in the right order. These files could be linked from source once their functions all match (`ESimsDataManager` still cannot, because of the shared inline virtuals problem in `CLAUDE.md`).
- **N bytes differ** with equal sizes (no file at the moment): the right amount of data in the wrong order or with a wrong constant. The first differing offset is where to start; the order of float constants is the order they are first used in the source. (`ECheats` and `ERFont` were of this kind; the cause was an empty string first in one and the header-string order in the other.)
- **sizes differ** (18 files): mostly files with functions still unwritten, whose strings and constants are therefore missing, so a smaller size on our side is expected. A larger size on our side (`Unk80023D3C`) means data the original puts elsewhere or an include that adds strings the original lacks.
- A first offset of `0x0` means the data differs from the very start, usually because the run of header strings differs (a stand-in header missing or included in a different order).
- **Tables of pointers always show as different.** The original object keeps those words as relocations (zero in the
  bytes), the compiled one has section offsets. `Unk80049ADC.cpp` first differs at 0x4FA for that reason (the house-name
  table); everything before it, the whole run of header strings, is identical. Compare the data after such a table.

