#!/usr/bin/env python3
"""Carry function names over from The Sims 2 (GameCube), which shares this game's
engine and was shipped with a symbol map.

The two games' function lists are aligned on runs of identical function sizes
(functions keep their source order inside a translation unit). Output:
config/G4ME69/sims2_hints.txt with one line per function:

    ADDR SIZE CONF NAME

CONF is `=` when the size is identical and the function sits in a run of at
least MIN_RUN identical sizes, or `~` when it lies between two such functions
with the same number of functions on both sides (size differs: treat as a guess).

Usage: tools/align_sims2.py SIMS2_SYMBOLS_TXT
"""
import difflib, re, sys
from pathlib import Path

root = Path(__file__).resolve().parent.parent
MIN_RUN = 3       # shortest run of equal sizes used as an anchor
WINDOW = 8        # how far to look for the next equal-size pair when extending

def load(path):
    out = []
    for line in open(path):
        m = re.match(r"(\S+) = \.(\w+):0x([0-9A-F]+); // type:function size:0x([0-9A-F]+)", line)
        if m and m.group(2) in ("text", "init"):
            out.append((int(m.group(3), 16), int(m.group(4), 16), m.group(1)))
    return sorted(out)

def main():
    a = load(root / "config/G4ME69/symbols.txt")
    b = load(sys.argv[1])
    sa = [x[1] for x in a]; sb = [x[1] for x in b]
    blocks = [m for m in difflib.SequenceMatcher(None, sa, sb, autojunk=False).get_matching_blocks() if m.size >= MIN_RUN]
    # Short runs of tiny functions (8/12-byte accessors) are not distinctive enough.
    blocks = [m for m in blocks if m.size >= 6 or len(set(sa[m.a:m.a + m.size])) >= 3]
    best = {}  # index in a -> (rank, index in b, conf)

    def put(i, j, conf, rank):
        if i not in best or best[i][0] < rank: best[i] = (rank, j, conf)

    def extend(i, j, step, rank):
        # Walk outward from an anchor, hopping to the nearest following equal-size pair.
        while True:
            found = None
            for d in range(2, 2 * WINDOW + 1):          # d = di + dj, smallest total skip first
                for di in range(1, d):
                    dj = d - di
                    if di > WINDOW or dj > WINDOW: continue
                    ii, jj = i + step * di, j + step * dj
                    if 0 <= ii < len(a) and 0 <= jj < len(b) and sa[ii] == sb[jj] and sa[ii] > 0x10:
                        found = (di, dj); break
                if found: break
            if not found: return
            di, dj = found
            if di == dj:
                for k in range(1, di): put(i + step * k, j + step * k, "~", rank - 1)
            i, j = i + step * di, j + step * dj
            put(i, j, "=", rank - (0 if di == dj == 1 else 1))

    for m in blocks:
        rank = m.size * 2
        for k in range(m.size): put(m.a + k, m.b + k, "=", rank + 1)
        extend(m.a + m.size - 1, m.b + m.size - 1, +1, rank)
        extend(m.a, m.b, -1, rank)

    out = root / "config/G4ME69/sims2_hints.txt"
    lines = [f"{a[i][0]:08X} {a[i][1]:#06x} {best[i][2]} {b[best[i][1]][2]}\n" for i in sorted(best)]
    out.write_text("".join(lines))
    exact = sum(1 for i in best if best[i][2] == "=")
    print(f"{len(best)} of {len(a)} functions named ({exact} exact-size, {len(best) - exact} guessed) -> {out.relative_to(root)}")

main()
