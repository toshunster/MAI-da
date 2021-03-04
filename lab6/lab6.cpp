/* Длинная арифметика.


12345678912344546464
8390573059734508734508
+

Операции:
 - Сложение (+)  *
 - Вычитание (-) *
 - Умножение (*) *
 - Сравнения (>, <, =) *
 - Деление (/)
 - Возведение в степень (^)
*/

#include "super_alg.hpp"

int main()
{
    super_alg::int100500_t num1, num2;
    char action;
    while (std::cin >> num1 >> num2 >> action) {
        // Сложение.
        if (action == '+') {
            super_alg::int100500_t res = num1 + num2;
            std::cout << res << "\n";
        }
        // Вычитание.
        else if (action == '-') {
            // O(n) + ...
            if (num1 < num2) {
                std::cout << "error" << std::endl;
                continue;
            }
            // ... + O(n) = O(2n) = O(n)
            super_alg::int100500_t res = num1 - num2;
            std::cout << res << "\n";
        }
        else if (action == '*') {
            super_alg::int100500_t res = num1 * num2;
            std::cout << res << "\n";
        }
        else if( action == '<' )
        {
            std::cout << ( ( num1 < num2 ) ? "true" : "false" ) << "\n";
        }
        else if( action == '=' )
        {
            std::cout << ( ( num1 == num2 ) ? "true" : "false" ) << "\n";
        }
    }
    return 0;
}

