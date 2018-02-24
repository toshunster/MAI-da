#!/usr/bin/env bash
source=lab6.cpp
bin=${source%.*}

if ! g++ -std=c++11 ${source} -o ${bin}; then
    echo "ERROR: Failed to compile file."
    exit 1
fi

rm -rf tests
mkdir -p tests
if ! python3 tests_generator.py 100 ; then
    echo "ERROR: Failed to python generate tests."
    exit 1
fi

for test_file in `ls tests/*.t`; do
    echo "Execute ${test_file}"
    if ! ./${bin} < $test_file > last_answer ; then
        echo "ERROR"
        continue
    fi
    answer_file="${test_file%.*}"

    if ! diff -u "${answer_file}.a" last_answer ; then
        echo "Failed"
    else
        echo "OK"
    fi 
done
