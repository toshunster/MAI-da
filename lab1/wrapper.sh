#! /usr/bin/env bash

set -o errexit
set -o nounset


function log_info()
{
  log_ "info" "$@"
}

function log_error()
{
  log_ "error" "$@"
}

function log_()
{
  local type=$1
  local message=$2
  local date_str=; date_str=$(gdate +'%Y-%m-%d %H:%M:%S')
  echo "[${type}] [${date_str}] ${message}"
}

function main()
{
  log_info "Stage #1 Compiling..."
  if ! make ; then
    log_error "Failed to compiled"
    return 1
  fi

  local test_dir=tests/
  rm -rf ${test_dir}
  mkdir ${test_dir}
  log_info "Stage #2 Test generating..."
  if ! python3 generator.py ${test_dir} ; then
    log_error "Failed to generate tests"
    return 1
  fi

  log_info "Stage #3 Checking..."
  for test_file in $( ls ${test_dir}/*.t ) ; do
    log_info "Running ${test_file}..."
    local tmp_output=tmp
    if ! ./lab1 < ${test_file} > ${tmp_output} ; then
      log_error "Failed to run test"
      return 1
    fi

    local answer_file=${test_file%.*}.a
    log_info "Comparing ${answer_file}..."
    if ! diff -u ${tmp_output} ${answer_file} ; then
      log_error "Failed to check test"
      return 1
    fi
  done
}

main $@
