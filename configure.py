#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "G4ME69",  # 0
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--ninja",
    metavar="BINARY",
    type=Path,
    help="path to ninja binary (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
parser.add_argument(
    "--warn",
    dest="warn",
    type=str,
    choices=["all", "off", "error"],
    help="how to handle warnings",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
# This game was built with SN Systems ProDG (GCC), which upstream decomp-toolkit
# can't analyze. Default to the patched build from tools/build_dtk.sh.
DTK_PRODG = Path("build") / "tools" / "dtk-prodg"
config.dtk_path = args.dtk or DTK_PRODG
if args.dtk is None and not DTK_PRODG.exists():
    sys.exit(f"{DTK_PRODG} not found. Run tools/build_dtk.sh first.")
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.generate_map = args.map
config.non_matching = args.non_matching
config.sjiswrap_path = args.sjiswrap
config.ninja_path = args.ninja
config.progress = args.progress
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-2"
config.compilers_tag = "20251118"
config.dtk_tag = "v1.8.3"
config.objdiff_tag = "v3.6.1"
config.sjiswrap_tag = "v1.2.2"
config.wibo_tag = "1.0.3"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym BUILD_VERSION={version_num}",
]
# SN Systems ProDG toolchain (ngccc / ngcld) instead of Metrowerks
config.prodg = True
config.prodg_ldscript = Path("config") / config.version / "ldscript.ld"
config.ldflags = []

# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []

# Optional numeric ID for decomp.me preset
# Can be overridden in libraries or objects
config.scratch_preset_id = None

# Base flags for ngccc (GCC 2.95.2, SN build). -O1 and -O3 are ruled out.
cflags_base = [
    "-O2",
    "-G8",
    # Vtables go to .rodata and inline/template functions are emitted as local
    # copies in every translation unit, as in the original.
    "-fno-weak",
    # Template repository: instances are emitted once, as global symbols, in the
    # unit chosen at link time (see tools/prodg_cc.py).
    "-frepo",
    "-fno-implement-inlines",
    # Plain `char` is signed (the code was ported from PS2), unlike the PowerPC default.
    "-fsigned-char",
    # STLport 4.5.3 (libs/stlport), configured as SN shipped it: no iostreams
    # library, no threads, and the old-style <new.h> runtime header.
    "-D_STLP_NO_OWN_IOSTREAMS",
    "-D_NOTHREADS",
    "-D_STLP_NO_NEW_NEW_HEADER",
    "-Ilibs/stlport",
    "-Ilibs/include",
    "-Iinclude",
    f"-Ibuild/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
]

if args.debug:
    cflags_base.extend(["-g", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

if args.warn == "all":
    cflags_base.append("-Wall")
elif args.warn == "off":
    cflags_base.append("-w")
elif args.warn == "error":
    cflags_base.append("-Werror")

config.linker_version = "ProDG/3.7"


# Helper for game / engine code
def GameLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": config.linker_version,
        "cflags": cflags_base,
        "progress_category": "game",
        "objects": objects,
    }


Matching = True                   # Object matches and should be linked
NonMatching = False               # Object does not match and should not be linked
Equivalent = config.non_matching  # Object should be linked when configured with --non-matching


# Object is only matching for specific versions
def MatchingFor(*versions):
    return config.version in versions


config.warn_missing_config = True
config.warn_missing_source = False
config.libs = [
    GameLib(
        "sims",
        [
            Object(NonMatching, "sims/ESimsApp.cpp"),
            Object(NonMatching, "sims/Unk800052C8.cpp"),
            Object(NonMatching, "sims/ESimsCam.cpp"),
            Object(NonMatching, "sims/cas/CASWidgets.cpp"),
            Object(NonMatching, "sims/cas/CASState.cpp"),
            Object(NonMatching, "sims/cas/CASTarget.cpp"),
            Object(NonMatching, "sims/cas/CASSelectors.cpp"),
            Object(NonMatching, "sims/cas/CASSim.cpp"),
            Object(NonMatching, "sims/cas/CASSkin.cpp"),
            Object(NonMatching, "sims/cas/Unk800230AC.cpp"),
            Object(NonMatching, "sims/cas/Unk80023D3C.cpp"),
        ],
    ),
]


# Optional callback to adjust link order. This can be used to add, remove, or reorder objects.
# This is called once per module, with the module ID and the current link order.
#
# For example, this adds "dummy.c" to the end of the DOL link order if configured with --non-matching.
# "dummy.c" *must* be configured as a Matching (or Equivalent) object in order to be linked.
def link_order_callback(module_id: int, objects: List[str]) -> List[str]:
    # Don't modify the link order for matching builds
    if not config.non_matching:
        return objects
    if module_id == 0:  # DOL
        return objects + ["dummy.c"]
    return objects


# Uncomment to enable the link order callback.
# config.link_order_callback = link_order_callback


# Optional extra categories for progress tracking
# Adjust as desired for your project
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "SDK Code"),
]
config.progress_each_module = args.verbose
# Optional extra arguments to `objdiff-cli report generate`
config.progress_report_args = [
    # Marks relocations as mismatching if the target value is different
    # Default is "functionRelocDiffs=none", which is most lenient
    # "--config functionRelocDiffs=data_value",
]

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress information
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
