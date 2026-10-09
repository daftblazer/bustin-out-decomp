#!/bin/sh
# Rebuild from scratch, verify main.dol, and commit only if it checks out.
# Usage: tools/commit_checked.sh "one-line message"
cd "$(dirname "$0")/.." || exit 1
rm -f build/G4ME69/main.dol
(ulimit -v $((16*1024*1024)); timeout 550 .venv/bin/ninja -j 8 >/tmp/ninja_last.log 2>&1)
if build/tools/dtk-prodg --no-color shasum -c config/G4ME69/build.sha1 2>&1 | grep -q "main.dol: OK"; then
    git add -A && git commit -q -m "$1" && git log --oneline | head -1
else
    echo "CHECK FAILED - not committing"; grep -E 'FAILED|rror' /tmp/ninja_last.log | head -3
    exit 1
fi
