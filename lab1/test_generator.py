#!/usr/bin/env python3

# -*- coding: utf8 -*-

import sys
import random
import string

MAX_KEY_VALUE = 100
MAX_VALUE_LEN = 10

def generate_random_value():
    return "".join( [ random.choice( string.ascii_lowercase ) for _ in range( 1, MAX_VALUE_LEN ) ] )

def main():
    if len(sys.argv) < 3:
        print("Usage: {} <output dir> <test count>".format(sys.argv[0]))
        sys.exit(1)

    output_dir = sys.argv[1]
    test_cnt = int(sys.argv[2])

    for num in range(1, test_cnt+1):
        values = list()
        output_filename_pattern = "{}/{:02d}".format(output_dir, num)
        output_filename = "{}.t".format(output_filename_pattern)
        with open( output_filename, 'w') as foutput:
            for _ in range( 0, random.randint( 0, 100 ) ):
                key = random.randint(0, MAX_KEY_VALUE)
                value = generate_random_value()
                values.append((key, value))
                foutput.write("{}\t{}\n".format(key, value))
        # Записываем файл с ответом.
        # values[0][0] -- key
        # values[0][1] -- value
        answer_filename = "{}.a".format(output_filename_pattern)
        with open(answer_filename, 'w') as fans:
            values = sorted(values, key=lambda x: x[0])
            for value in values:
                fans.write("{}\t{}\n".format(value[0], value[1]))

if __name__ == "__main__":
    main()
