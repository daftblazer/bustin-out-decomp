#!/usr/bin/env python3
"""Pair one engine class's methods in The Sims 2's symbol list with our functions.

Pairs are made only where the size is identical, the order is the same, and the
functions sit in a run of at least 3 pairs with at least 3 distinct sizes, two of them over 0x10, all
within one cluster of addresses (0x2000). Runs of tiny accessors alone are
not distinctive and are ignored, and so is any run whose size sequence occurs more than
once in the code (storable boilerplate). Nothing is renamed; the pairs are printed as
"ADDR SIZE Class::Method" lines.

Usage: tools/engine_names.py ClassName [more classes...]
"""
import difflib, re, sys
from pathlib import Path

root = Path(__file__).resolve().parent.parent
LO, HI = 0x800034A0, 0x8026FE50      # GCC code: game and engine (Metrowerks SDK excluded)

def load(path, text_only=True):
    out = []
    for line in open(path):
        m = re.match(r"(\S+) = \.(\w+):0x([0-9A-F]+); // type:function size:0x([0-9A-F]+)", line)
        if m and m.group(2) in ("text", "init"):
            out.append((int(m.group(3), 16), int(m.group(4), 16), m.group(1)))
    return sorted(out)

def pairs_for(cls, ours, theirs_all):
    theirs = [t for t in theirs_all if t[2].startswith(cls + "__")]
    if len(theirs) < 5: return []
    sa = [o[1] for o in ours]; sb = [t[1] for t in theirs]
    blocks = [m for m in difflib.SequenceMatcher(None, sa, sb, autojunk=False).get_matching_blocks()
              if m.size >= 3 and len(set(sa[m.a:m.a + m.size])) >= 3
              and len([x for x in set(sa[m.a:m.a + m.size]) if x > 0x10]) >= 2]
    if not blocks: return []
    # keep the blocks near the biggest one (one class sits in one stretch of code)
    centre = ours[max(blocks, key=lambda m: m.size).a][0]
    blocks = [m for m in blocks if abs(ours[m.a][0] - centre) <= 0x2000]
    # A run whose size sequence also occurs elsewhere cannot be assigned by size (the
    # storable boilerplate of every class has the same sizes), so it is dropped.
    def occurrences(seq):
        n = len(seq)
        return sum(1 for i in range(len(sa) - n + 1) if sa[i:i + n] == seq)
    blocks = [m for m in blocks if occurrences(sa[m.a:m.a + m.size]) == 1]
    out = []
    for m in blocks:
        for k in range(m.size):
            o, t = ours[m.a + k], theirs[m.b + k]
            out.append((o[0], o[1], o[2], t[2]))
    return out

def main():
    ours = [o for o in load(root / "config/G4ME69/symbols.txt") if LO <= o[0] < HI]
    theirs = load(root / "reference/sims2_symbols.txt")
    for cls in sys.argv[1:]:
        res = pairs_for(cls, ours, theirs)
        print("# %s: %d pairs" % (cls, len(res)), file=sys.stderr)
        for addr, size, ourname, name in res:
            print("%08X 0x%X %s::%s" % (addr, size, cls, name[len(cls) + 2:]))

if __name__ == "__main__":
    main()
