# -*- coding: utf-8 -*-

import sys
import random

# Максимально возможное значение числа.
MAX_POW = 40
MAX_VALUE = 100 ** MAX_POW
MIN_VALUE = 1

def get_random_int():
    return random.randint(MIN_VALUE, 100 ** random.randint(1, MAX_POW))

def get_random_nums():
    return get_random_int(), get_random_int()

def get_answer( num1, num2, operation ):
    if operation == "+":
        return str( num1 + num2 )
    elif operation == "-":
        return str( num1 - num2 ) if num1 > num2 else "error"
    elif operation == "*":
        return str( num1 * num2 )
    elif operation == "<":
        # num1 < num2 вернёт True или False, чтобы
        # получить true или false, то сначала необходимо
        # привести его к int'у, а потом уже в строку.
        return str( num1 < num2 ).lower()

if __name__ == "__main__":
    # Ожидаем, что будет два аргумента: название программы и
    # количество тестов.
    if len( sys.argv ) != 2:
        print( "Usage: %s <tests count>" % sys.argv[0] )
        sys.exit(1)
    
    # Считываем количество тестов для каждой операции.
    tests_count = int( sys.argv[1] )

    # Пробегаемся по операция, для которых мы хотим
    # сгенерировать тесты.
    for enum, operation in enumerate( [ "+", "-", "*", "<" ] ):

        # Открываем файлы для записи самих тестов и ответов 
        # к ним.
        filename_pattern = 'tests/{:02}'.format( enum+1 )
        with open( '{}.t'.format( filename_pattern ), 'w' ) as test_file, \
             open( '{}.a'.format( filename_pattern ), 'w' ) as answer_file:
            for i in range(0, tests_count):
                # Генерируем рандомные числа.
                num1, num2 = get_random_nums()
                # Записываем в файл получившийся тест.
                test_file.write( "%d\n%d\n%s\n" % ( num1, num2, operation ) )
                # Получаем ответ в виде строки и записываем его
                # в файл с ответами.
                answer = get_answer( num1, num2, operation )
                answer_file.write( "%s\n" % answer )
