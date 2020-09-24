#include <iostream>
#include <chrono>

#include "sort.hpp"
#include "vector.hpp"

//using duration_t = std::chrono::microseconds;
using duration_t = std::chrono::milliseconds;

int main()
{
    vector::Vector<Pair> input, input_stl;
    int key;
    std::string value;
    while (std::cin >> key >> value)
    {
        input.push_back( Pair(key, value) );
    }
    input_stl = input;

    std::cout << "Let's rock" << std::endl;

    // Измеряем время работы сортировки подсчётом.
    std::chrono::time_point<std::chrono::system_clock> start_ts = std::chrono::system_clock::now();
    sort::counting_sort( input );
    auto end_ts = std::chrono::system_clock::now();
    uint64_t counting_sort_ts = std::chrono::duration_cast<duration_t>( end_ts - start_ts ).count();

    // Измеряем время работы stl сортировки.
    start_ts = std::chrono::system_clock::now();
    std::stable_sort(std::begin(input_stl), std::end(input_stl));
    end_ts = std::chrono::system_clock::now();

    uint64_t stl_sort_ts = std::chrono::duration_cast<duration_t>( end_ts - start_ts ).count();
    std::cout << "Counting sort time: " << counting_sort_ts << "ms" << std::endl;
    std::cout << "STL sort time: " << stl_sort_ts << "ms" << std::endl;
}
