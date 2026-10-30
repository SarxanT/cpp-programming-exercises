#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
for source in ./*.cpp; do
    program="$tmp/$(basename "${source%.cpp}")"
    echo "Checking $source"
    g++ -std=c++17 -Wall -Wextra -pedantic "$source" -o "$program"
    "$program" > /dev/null
done
echo "All six C++ examples compiled and completed their smoke tests."
