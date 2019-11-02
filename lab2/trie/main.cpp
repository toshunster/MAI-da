#include <iostream>
#include <vector>
#include <cassert>

#include "trie.hpp"

int main()
{
    trie::Trie tree;

    std::string word;
    std::vector<std::string> words;

    while( std::cin >> word ) {
        tree.insert( word );
        words.push_back( word );
    }

    // TODO: познакомить народ с unittest,
    // а не вот это вот всё.

    // Ищем полное вхождение.
    for( auto word : words ) {
        assert(tree.find(word));
    }

    // Ищем незнакомое словечко.
    {
        std::string unknown_word = "gustavo";
        assert( !tree.find(unknown_word) );
    }

    // Ищем префиксы и проверим, что не находим эти префиксы.
    for( auto word : words ) {
        std::string prefix = word.substr(0, word.size()-1);
        assert( tree.startsWith(prefix) );
        assert( !tree.find(prefix) );
    }

    // Ищем несуществующие префиксы и несуществующие слова.
    for( auto word : words ) {
        // На самом деле плохо так делать, но я сделаю.
        // Почему плохо? Потому что это не гарантия того, что
        // префикса с суффиксом z не окажется.
        // Но 01.t подобран таким образом, что пройдёт проверку.
        std::string prefix = word.substr(0, word.size()-1) + "z";
        std::string unknown_word = word + "m";

        assert( !tree.startsWith(prefix) );
        assert( !tree.find(prefix) );
    }

    std::cout << "OK" << std::endl;
    return 0;
}

