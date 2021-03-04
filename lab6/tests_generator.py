#! /usr/bin/env python

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

def get_answer(num1, num2, operation):
    if operation == "+":
        return str(num1 + num2)
    if operation == "-":
        return str(num1 - num2) if num1 >= num2 else "error"
    if operation == "*":
        return str(num1 * num2)
    if operation == "<":
        # num1 < num2 вернёт True или False, чтобы
        # получить true или false, то сначала необходимо
        # привести его к int'у, а потом уже в строку.
        return str(num1 < num2).lower()
    if operation == "=":
        # Аналогично как для оператора <.
        return str(num1 == num2).lower()
    return None

def main():
    # Ожидаем, что будет три аргумента: название программы,
    # путь до директории с тестами и количество тестов в каждом
    # файле.
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <tests directory> <tests count>")
        sys.exit(1)

    # Считываем путь до папки с тестами.
    test_dir = sys.argv[1]
    # Считываем количество тестов для каждой операции.
    tests_count = int(sys.argv[2])

    # Пробегаемся по операциям, для которых мы хотим
    # сгенерировать тесты.
    for enum, operation in enumerate(["+", "-", "*", "<", "="]):
        # Открываем файлы для записи самих тестов и ответов
        # к ним.
        filename_pattern = f'{test_dir}/{enum+1:02}'
        with open(f'{filename_pattern}.t', 'w') as test_file, \
             open(f'{filename_pattern}.a', 'w') as answer_file:
            for _ in range(0, tests_count):
                # Генерируем рандомные большие числа.
                num1, num2 = get_random_nums()
                # Записываем в файл получившийся тест.
                test_file.write(f"{num1}\n{num2}\n{operation}\n")
                # Получаем ответ в виде строки и записываем его
                # в файл с ответами.
                answer = get_answer(num1, num2, operation)
                answer_file.write(f"{answer}\n")

if __name__ == "__main__":
    main()
