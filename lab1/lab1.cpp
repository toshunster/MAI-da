#include <iostream>
#include <vector>

struct KV
{
    int key;
    std::string value;
};

void countingSort( const std::vector<KV> &elems,
                   int max_key,
                   std::vector<KV> &output )
{
    std::vector<int> tmp(max_key+1, 0);
    for( auto &elem : elems )
    {
        ++tmp[elem.key];
    }

    for( size_t i = 1; i < tmp.size(); ++i )
    {
        tmp[i] += tmp[i-1];
    }

    for( int i = elems.size()-1; i >= 0; --i )
    {
        output[ tmp[elems[i].key] - 1 ] = elems[i];
        tmp[elems[i].key]--;
    }
}

int main()
{
    KV kv_elem;
    std::vector<KV> elems;
    int max_key = std::numeric_limits<int>::min();

    // Считываем ключ-значение из стандартного ввода.
    while( std::cin >> kv_elem.key >> kv_elem.value ) {
        max_key = std::max( kv_elem.key, max_key );
        elems.push_back( kv_elem );
    }

    std::vector<KV> result( elems.size() );

    countingSort( elems, max_key, result );

    for( auto &elem : result )
    {
        std::cout << elem.key << "\t" << elem.value << std::endl;
    }

    return 0;
}

