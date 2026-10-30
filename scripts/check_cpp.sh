#!/usr/bin/env bash
set -euo pipefail

cd "$(dirname "$0")/.."

shopt -s nullglob
sources=( ./*.cpp )
if (( ${#sources[@]} == 0 )); then
  echo "::error::No C++ source files found in the repository root." >&2
  exit 1
fi

tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT

for source in "${sources[@]}"; do
  program="$tmp/$(basename "${source%.cpp}")"
  echo "Compiling $source"
  g++ -std=c++17 -Wall -Wextra -pedantic "$source" -o "$program"
  echo "Smoke-testing $source"
  timeout 15s "$program" > /dev/null
done

echo "Success: ${#sources[@]} C++ examples compiled and passed smoke tests."
