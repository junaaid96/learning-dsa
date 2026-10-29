#!/usr/bin/env bash
# run_all.sh - compile and run every .cpp file in this repository.
#
# Usage:   ./run_all.sh            (uses g++ by default)
#          CXX=clang++ ./run_all.sh
#          ./run_all.sh graphs     (only files under the given folder)
#
# Every file is compiled with -std=c++17 -Wall -Wextra and executed.
# A file passes when it compiles and its program exits with status 0
# (each main() runs assert-based self-checks).

set -u
CXX="${CXX:-g++}"
FLAGS="-std=c++17 -O2 -Wall -Wextra"
ROOT="$(cd "$(dirname "$0")" && pwd)"
TARGET="${1:-.}"
BUILD="$(mktemp -d)"
trap 'rm -rf "$BUILD"' EXIT

pass=0; fail=0; failed=()
while IFS= read -r -d '' file; do
    rel="${file#"$ROOT"/}"
    exe="$BUILD/$(echo "$rel" | tr '/.' '__')"
    if ! "$CXX" $FLAGS "$file" -o "$exe" 2> "$exe.log"; then
        echo "COMPILE FAIL  $rel"; cat "$exe.log"; fail=$((fail+1)); failed+=("$rel"); continue
    fi
    if [ -s "$exe.log" ]; then echo "WARNINGS      $rel"; cat "$exe.log"; fi
    if "$exe" < /dev/null > "$exe.out" 2>&1; then
        echo "PASS          $rel"; pass=$((pass+1))
    else
        echo "RUN FAIL      $rel"; cat "$exe.out"; fail=$((fail+1)); failed+=("$rel")
    fi
done < <(cd "$ROOT" && find "$ROOT/$TARGET" -name '*.cpp' -not -path '*/.git/*' -not -path '*/website/*' -print0 | sort -z)

echo
echo "Passed: $pass  Failed: $fail"
if [ "$fail" -ne 0 ]; then printf '  %s\n' "${failed[@]}"; exit 1; fi
