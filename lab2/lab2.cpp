#include <iostream>

#include "bst.hpp"

// exec(main)
int main()
{
    bst::BST<int64_t, std::string> root;
    std::string action;
    while (std::cin >> action)
    {
        if (action == "+")
        {
            int64_t key;
            std::string value;
            std::cin >> key >> value;
            if( root.insert(key, value) )
            {
                std::cout << "OK\n";
            }
            else
            {
                std::cout << "Exists\n";
            }
        }
        else if (action == "-")
        {
            // ...
        }
        // В action будет ключ, который нужно найти.
        else
        {
            int64_t key = std::stoll(action);

            // Аналог structured binding (C++17).
            /*
             * std::tuple<bool, std::string> t = root.find(key);
             * bool success = std::get<0>(t);
             * std::string value = std::get<1>(t);
             */
            auto [success, value] = root.find(key);
            if (success)
            {
                std::cout << "OK: " << value << "\n";
            }
            else
            {
                std::cout << "NoSuchWord\n";
            }
        }
    }
    return 0;
}
