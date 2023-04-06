#! /usr/bin/env python3

import sys
import random
import string

def get_random_key():
    return random.randint(1, 2 ** 63 - 1)

def get_random_value():
    # pip install faker
    str_len = random.randint(1, 100)
    return "".join([random.choice(string.ascii_letters) for _ in range(str_len)])

if __name__ == "__main__":
    # Проверяем, что передали 1 аргумент.
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <test dir> <count of tests>")
        sys.exit(1)

    test_dir = sys.argv[1]
    count_of_tests = int(sys.argv[2])

    actions = [ "+", "?" ]

    for enum in range(count_of_tests):
        keys = dict()
        test_file_name = f"{test_dir}/{enum+1:02d}"
        with open("{0}.t".format(test_file_name), 'w') as output_file, \
             open("{0}.a".format(test_file_name), "w") as answer_file:

            # Для каждого файла генерируем от 1 до тысячи операций.
            for _ in range( random.randint(10 ** 3, 10 ** 5) ):
                action = random.choice(actions)
                if action == "+":
                    key = get_random_key()
                    value = get_random_value()
                    output_file.write(f"+ {key} {value}\n")
                    # Если в нашем словаре уже есть такой ключ, то ответе должно быть
                    # сказано, что он существует, иначе --- успешное добавление.
                    answer = "Exists"
                    if key not in keys:
                        answer = "OK"
                        keys[key] = value
                    answer_file.write(f"{answer}\n")

                elif action == "?":
                    search_exist_element = random.choice([True, False])
                    key = random.choice([key for key in keys.keys() ]) if search_exist_element and len(keys.keys()) > 0 else get_random_key()
                    output_file.write("{0}\n".format(key))
                    if key in keys:
                        answer = "OK: {0}".format(keys[key])
                    else:
                        answer = "NoSuchWord"
                    answer_file.write("{0}\n".format(answer))
