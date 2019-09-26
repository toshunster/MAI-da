#include <iostream>

#include "bst.hpp"


int main()
{
    bst::Tree root;
    char key;
    int value;
    char action;
    while( std::cin >> action ) {
        // Операция добавления,...
        if( action == '+' ) {
            std::cin >> key >> value;
            root.Insert( tolower( key ), value );
        }
        // другие else if
        // ...
        // иначе поиск.
        else {
            // В качестве ключа выступает тут action.
            char key = tolower( action );
            root.Search( key );
        }
    }

    return 0;
}
