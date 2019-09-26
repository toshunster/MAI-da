#! /usr/bin/env bash

set -o errexit
set -o pipefail
set -o nounset

function main() {
  local source=lab2.cpp
  local bin=${source%.*}

  if ! ( make clean && make ) ; then
    echo "ERROR: Failed to compile file."
    exit 1
  fi

  local test_dir=tests
  rm -rf ${test_dir}
  mkdir -p ${test_dir}
  if ! python3 test_generator.py 10 ; then
    echo "ERROR: Failed to python generate tests."
    exit 1
  fi

  for test_file in $(ls ${test_dir}/*.t); do
    echo "Execute ${test_file}"
    if ! ./${bin} < ${test_file} > tmp ; then
      echo "ERROR"
      continue
    fi
    answer_file="${test_file%.*}"

    if ! diff -u "${answer_file}.a" tmp ; then
      echo "Failed"
    else
      echo "OK"
    fi
  done
}

main $@
