#! /usr/bin/env bash

set -o errexit
set -o nounset

readonly TESTS_DIR=tests

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
  local date_str=; date_str=$(date +'%Y-%m-%d %H:%M:%S')
  echo "[${type}] [${date_str}] ${message}"
}

function main()
{
  local bin=lab2
  log_info "Stage #1. Compiling..."
  if ! make ; then
    log_error "Failed to compile lab2.cpp"
    return 1
  fi
  log_info "Compiling OK"

  log_info "Stage #2. Test generating..."
  rm -rf ${TESTS_DIR}
  mkdir ${TESTS_DIR}
  local count_of_tests=3
  if ! ./test_generator.py ${TESTS_DIR} ${count_of_tests} ; then
    log_error "Failed to generate tests"
    return 1
  fi
  log_info "Generating OK"

  log_info "Stage #3 Checking..."
  for test_file in $( ls ${TESTS_DIR}/*.t ) ; do
    local tmp_output=tmp
    if ! ./${bin} < ${test_file} > ${tmp_output} ; then
      log_error "Failed to run test"
      return 1
    fi
    local file_line_cnt=; file_line_cnt=$(cat ${test_file} | wc -l | sed -e 's/ *//g')
    local answer_file=${test_file%.*}.a
    if ! diff -u ${answer_file} ${tmp_output} ; then
      log_error "Failed to check test ${test_file}."
      return 1
    fi
    log_info "${test_file}, lines=${file_line_cnt} OK"
  done

  log_info "Stage #4 Benchmarking..."
  #if ! make benchmark ; then
  #  log_info "Failed to compile benchmark."
  #  return 1
  #fi
  #local benchmark_bin=./benchmark
  #for test_file in $( ls ${TESTS_DIR}/*.t ) ; do
  #  log_info "Running ${test_file}"
  #  if ! ${benchmark_bin} < ${test_file} ; then
  #    log_error "Failed to run ${benchmark_bin} for ${test_file}."
  #    return 1
  #  fi
  #done
}

# $1 -- первый аргумент
# %2 -- второй аргумент
# $@ -- все аргументы
main $@
