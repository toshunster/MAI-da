#pragma once

#include <iostream>
#include "vector.hpp"

/*struct Pair
{
    Pair() {}
    Pair(int k, char v) : key(k), value(v)
    {
        // key2 = k; -- ошибка
    }
    ~Pair() {}

    bool operator<(const Pair &rhs) { return key < rhs.key; }

    int key;
    char value;
};*/

using Pair = std::pair<int, std::string>;

namespace sort
{

class CountingSort
{
    public:
        CountingSort() {}
        ~CountingSort() {}
        void sort();
};

void counting_sort(vector::Vector<Pair> &elems);

}
