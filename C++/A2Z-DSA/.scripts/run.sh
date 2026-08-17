#!/usr/bin/env bash

set -euo pipefail

if [[ -n "${ZED_WORKTREE_ROOT:-}" ]]; then
    ROOT="$ZED_WORKTREE_ROOT"
    FILE="$ZED_FILE"
    RELATIVE="$ZED_RELATIVE_FILE"
else
    if [[ $# -ne 1 ]]; then
        echo "Usage:"
        echo "  run.sh path/to/File.java"
        exit 1
    fi

    ROOT="$(git rev-parse --show-toplevel 2>/dev/null || pwd)"
    FILE="$(basename "$1")"
    RELATIVE="${1#"$ROOT"/}"
fi

cd "$ROOT"

EXT="${FILE##*.}"
NAME="$(basename "$FILE" ".$EXT")"
DIR="$(dirname "$RELATIVE")"

TIME_CMD="/usr/bin/time -v --output \"$ROOT/sys.txt\""
TIMEOUT_CMD="timeout 5"

cleanup() {
    rm -f "$DIR/$NAME.class" \
          "$DIR/$NAME.out" \
          "$DIR/$NAME"
}

trap cleanup EXIT

echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "Running: $RELATIVE"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

case "$EXT" in

    java)
        javac "$RELATIVE"

        eval "$TIME_CMD" \
            $TIMEOUT_CMD \
            java -cp "\"$DIR\"" "$NAME" \
            \< "\"$ROOT/input.txt\"" \
            \> "\"$ROOT/output.txt\""
        ;;

    cpp|cc|cxx)

        g++ \
            -std=c++20 \
            -O2 \
            -Wall \
            "$RELATIVE" \
            -o "$DIR/$NAME.out"

        eval "$TIME_CMD" \
            $TIMEOUT_CMD \
            "\"$DIR/$NAME.out\"" \
            \< "\"$ROOT/input.txt\"" \
            \> "\"$ROOT/output.txt\""
        ;;

    c)

        gcc \
            -O2 \
            "$RELATIVE" \
            -o "$DIR/$NAME.out"

        eval "$TIME_CMD" \
            $TIMEOUT_CMD \
            "\"$DIR/$NAME.out\"" \
            \< "\"$ROOT/input.txt\"" \
            \> "\"$ROOT/output.txt\""
        ;;

    py)

        eval "$TIME_CMD" \
            $TIMEOUT_CMD \
            python3 "\"$RELATIVE\"" \
            \< "\"$ROOT/input.txt\"" \
            \> "\"$ROOT/output.txt\""
        ;;

    go)

        go build -o "$DIR/$NAME" "$RELATIVE"

        eval "$TIME_CMD" \
            $TIMEOUT_CMD \
            "\"$DIR/$NAME\"" \
            \< "\"$ROOT/input.txt\"" \
            \> "\"$ROOT/output.txt\""
        ;;

    rs)

        cargo run \
            --quiet \
            < "$ROOT/input.txt" \
            > "$ROOT/output.txt"
        ;;

    *)

        echo "Unsupported language: .$EXT"
        exit 1
        ;;

esac

echo
echo "✓ Finished."
echo "Output  : output.txt"
echo "Stats   : sys.txt"
