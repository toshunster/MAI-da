void push_back();
#include <iostream>

#include "vector.hpp"
#include "sort.hpp"

/*
 * int -- ключ;
 * std::string -- значение;
 */
int main()
{
    int key;
    std::string value;

    vector::Vector<Pair> elems;
    while (std::cin >> key >> value)
    {
        elems.push_back( Pair(key, value) );
    }

    // Сортировка подсчётом.
    sort::counting_sort( elems );

    for (Pair elem : elems)
    {
        std::cout << elem.first << " " << elem.second << std::endl;
    }

    return 0;
}
