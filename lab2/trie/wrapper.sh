#! /usr/bin/env bash

set -o errexit
set -o pipefail
set -o nounset

function main() {
  local source=main.cpp
  local bin=trie

  if ! ( make clean && make ) ; then
    echo "ERROR: Failed to compile file."
    exit 1
  fi

  local test_dir=tests
  for test_file in $(ls ${test_dir}/*.t); do
    echo "Execute ${test_file}"
    if ! ./${bin} < ${test_file} ; then
      echo "ERROR"
      continue
    fi
    echo "OK"
  done
}

main $@
