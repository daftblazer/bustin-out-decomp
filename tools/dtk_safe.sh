#!/bin/sh
# Run dtk with a hard memory cap and time limit so a runaway analysis can't exhaust RAM.
# Usage: tools/dtk_safe.sh [dtk args...]
ulimit -v $((6 * 1024 * 1024))  # 6 GiB of address space
exec timeout "${DTK_TIMEOUT:-300}" "$(dirname "$0")/../build/tools/dtk-prodg" "$@"
