#!/usr/bin/env bash

set -o errexit
set -o pipefail
set -o nounset

function main() {
  # Компилируем.
  if ! make ; then
    echo "ERROR: Failed to compile file."
    exit 1
  fi

  local test_dir=tests
  rm -rf ${test_dir}
  mkdir -p ${test_dir}

  # Генерируем тесты.
  if ! python3 test_generator.py ${test_dir} 10 ; then
    echo "ERROR: Failed to python generate tests."
    exit 1
  fi

  # Запускаем тесты и сравниваем ответ.
  for test_file in $(ls ${test_dir}/*.t); do
    echo "Execute ${test_file}"

    local output_file=tmp
    local exe_file=lab1
    if ! ./${exe_file} < ${test_file} > ${output_file} ; then
      echo "ERROR"
      continue
    fi

    answer_file="${test_file%.*}"
    if ! diff -u ${answer_file}.a ${output_file} ; then
      echo "Failed"
    else
      echo "OK"
    fi
    rm -f ${output_file}
  done
  rm -rf ${test_dir}
}

main $@
