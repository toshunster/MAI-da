#include "sort.hpp"

namespace sort
{

void CountingSort::sort()
{
    return;
}

/*
 * int - ключ
 * std::string - значение
 */
void counting_sort( vector::Vector<Pair> &elems )
{
    int32_t max_elem = 0;
    // std::max_element(std::begin(elems), std::end(elems));

    for (size_t i = 0; i < elems.size(); ++i)
    {
        auto pair = elems[i];
        max_elem = std::max(max_elem, pair.first);
    }

    vector::Vector<int> tmp(max_elem + 1);
    // A = { 3, 2, 3, 1 }
    // tmp = { 0 1 1 2 }
    for (size_t i = 0; i < elems.size(); ++i)
    {
        ++tmp[elems[i].first];
    }

    // tmp = { 0 1 2 4 }
    for (size_t i = 1; i < tmp.size(); ++i)
    {
        tmp[i] += tmp[i-1];
    }

    vector::Vector<Pair> result( elems.size() );
    for (int i = elems.size()-1; i >= 0; --i )
    {
        auto key = elems[i].first;
        auto pos = tmp[key]--;
        result[pos-1] = elems[i];
    }

    std::swap(elems, result);
}

}

