#!/usr/bin/env python3
"""Rewrite the progress section of README.md from the last build.

Reads build/G4ME69/report.json (written by ninja) and config/G4ME69/symbols.txt,
and replaces everything between the two progress markers in README.md.
Usage: .venv/bin/python tools/readme_progress.py
"""
import json, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REPORT = os.path.join(ROOT, "build", "G4ME69", "report.json")
SYMBOLS = os.path.join(ROOT, "config", "G4ME69", "symbols.txt")
README = os.path.join(ROOT, "README.md")
START, END = "<!-- progress:start -->", "<!-- progress:end -->"

# Address ranges of the binary by origin (see CLAUDE.md, "Layout of the binary").
AREAS = [
    ("Game code (`sims/`)", [(0x800034A0, 0x80109968)], "src/sims/"),
    ("EOR engine (`engine/`)", [(0x80153C2C, 0x80270064)], "src/engine/"),
    ("C/C++ runtime and libraries", [(0x8010C824, 0x80118124), (0x8012AD10, 0x80152074), (0x8028FF78, 0x80291CA0)], None),
    ("Dolphin SDK (Metrowerks)", [(0x80118124, 0x8012AD10), (0x80152074, 0x80153C2C), (0x80270064, 0x8028FF78)], None),
    ("SN debugger stub (`libsn`)", [(0x80109968, 0x8010C824)], None),
]
COLOR = "3828f7"


def bar(fraction, width=20):
    filled = int(round(fraction * width))
    if fraction > 0 and filled == 0:
        filled = 1
    return "█" * filled + "░" * (width - filled)


def badge(label, value):
    text = lambda s: s.replace("-", "--").replace("_", "__").replace(" ", "_").replace("%", "%25").replace("/", "%2F")
    return f'<img src="https://img.shields.io/badge/{text(label)}-{text(value)}-{COLOR}" alt="{label}: {value}">'


def main():
    if not os.path.exists(REPORT):
        sys.exit("no build/G4ME69/report.json: run ninja first")
    report = json.load(open(REPORT))
    m = report["measures"]

    # Size of every function, from the symbol list.
    functions = []
    for line in open(SYMBOLS):
        k = re.match(r"\S+ = \.(?:text|init):0x([0-9A-Fa-f]+); // type:function size:0x([0-9A-Fa-f]+)", line)
        if k:
            functions.append((int(k.group(1), 16), int(k.group(2), 16)))

    units = []
    for u in report["units"]:
        path = u.get("metadata", {}).get("source_path")
        if path and not u["metadata"].get("auto_generated"):
            um = u["measures"]
            units.append({
                "path": path,
                "code": int(um.get("total_code", 0)),
                "matched": int(um.get("matched_code", 0)),
                "functions": um.get("total_functions", 0),
                "matched_functions": um.get("matched_functions", 0),
                "linked": bool(u["metadata"].get("complete")),
            })

    out = [START, ""]
    out.append('<p align="center">')
    out.append("  " + badge("Code matched", "%.2f%%" % m["matched_code_percent"]))
    out.append("  " + badge("Functions matched", "%s / %s" % (format(m["matched_functions"], ","), format(m["total_functions"], ","))))
    out.append("  " + badge("Linked from source", "%d files" % m["complete_units"]))
    out.append("</p>")
    out.append("")
    out.append("| Part of the binary | Functions | Code matched | |")
    out.append("|---|---:|---:|---|")
    for name, ranges, prefix in AREAS:
        inside = [(a, s) for a, s in functions if any(lo <= a < hi for lo, hi in ranges)]
        total = sum(s for _, s in inside)
        matched = sum(u["matched"] for u in units if prefix and u["path"].startswith(prefix))
        matched_fn = sum(u["matched_functions"] for u in units if prefix and u["path"].startswith(prefix))
        fraction = matched / total if total else 0.0
        out.append("| %s | %s / %s | %.2f%% | `%s` |" % (name, format(matched_fn, ","), format(len(inside), ","), 100 * fraction, bar(fraction)))
    total = int(m["total_code"])
    fraction = int(m["matched_code"]) / total
    out.append("| **Whole executable** | **%s / %s** | **%.2f%%** | `%s` |" % (
        format(m["matched_functions"], ","), format(m["total_functions"], ","), 100 * fraction, bar(fraction)))
    out.append("")
    out.append("A function counts as matched only when its C++ source compiles to the original bytes.")
    out.append("The Dolphin SDK parts were built with a different compiler and are not decompiled by hand here.")
    out.append("")
    out.append("<details>")
    out.append("<summary>Source files (%d)</summary>" % len(units))
    out.append("")
    out.append("| File | Functions | Code matched | | Linked from source |")
    out.append("|---|---:|---:|---|:---:|")
    for u in sorted(units, key=lambda u: u["path"]):
        fraction = u["matched"] / u["code"] if u["code"] else 0.0
        out.append("| `%s` | %d / %d | %.1f%% | `%s` | %s |" % (
            u["path"], u["matched_functions"], u["functions"], 100 * fraction, bar(fraction, 10), "yes" if u["linked"] else ""))
    out.append("")
    out.append("A file is linked from source once every function in it matches and its data is split out;")
    out.append("until then the build uses the original bytes for that file.")
    out.append("")
    out.append("</details>")
    out.append("")
    out.append(END)

    text = open(README).read()
    i, j = text.index(START), text.index(END) + len(END)
    open(README, "w").write(text[:i] + "\n".join(out) + text[j:])
    print("README.md: %.2f%% code, %d / %d functions" % (m["matched_code_percent"], m["matched_functions"], m["total_functions"]))


if __name__ == "__main__":
    main()
