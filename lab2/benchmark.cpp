#include <iostream>
#include <map>
#include <chrono>

#include "bst.hpp"

using duration_t = std::chrono::microseconds;

int main() {
    std::map<char, uint32_t> rb_tree;
    bst::Tree bst_tree;
    char action;
    char key;
    uint32_t value;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    int64_t rb_ts = 0, bst_ts = 0;
    while( std::cin >> action ) {
        if( action == '+' ) {
            std::cin >> key >> value;
            {
                start = std::chrono::system_clock::now();
                rb_tree.insert( {key, value} );
                end = std::chrono::system_clock::now();
                rb_ts += std::chrono::duration_cast<duration_t>( end - start ).count();
            }
            {
                start = std::chrono::system_clock::now();
                bst_tree.Insert( key, value );
                end = std::chrono::system_clock::now();
                bst_ts += std::chrono::duration_cast<duration_t>( end - start ).count();
            }
        }
    }
    std::cout << "std::map ms=" << rb_ts << "\nbst ms=" << bst_ts << std::endl;
}

