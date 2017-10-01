
if ! g++ -std=c++11 lab1.cpp -o lab1; then
    echo "ERROR: Failed to compile file."
    exit 1
fi

if ! python3 test_generator.py ; then
    echo "ERROR: Failed to python generate tests."
    exit 1
fi

for test_file in `ls tests/*.t`; do
    echo "Execute ${test_file}"
    if ! ./lab1 < $test_file > tmp ; then
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