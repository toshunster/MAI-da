#include <map>
#include <vector>
#include <iostream>
#include <sstream>

const char TERMINAL = '$';

using vec_t = std::vector<size_t>;

class SuffixNode {
public:
    int number = -1;
    std::map<char, SuffixNode> m_data;
};

class SuffixTree {
public:
    SuffixTree( const std::string & pattern ) { Build( pattern + TERMINAL ); }
    ~SuffixTree() {}
    bool Search( const std::string & text, vec_t &pos ); 
private:
    void Build( const std::string & );
    void AddSuffix( const std::string &, size_t );
    void CollectPositions( const SuffixNode *node, vec_t &pos );
private:
    SuffixNode root;
};

void
SuffixTree::Build( const std::string & pattern ) {
    for( size_t i = 0; i < pattern.size(); ++i ) {
        std::string suffix = pattern.substr( i, pattern.size() - i );
        AddSuffix( suffix, i+1 );
    }
}

void
SuffixTree::AddSuffix( const std::string & suffix, size_t number) {
    SuffixNode *node = &root;
    for( size_t i = 0; i < suffix.size(); ++i ) {
        const char *sign = &suffix[i];
        auto it = node->m_data.find( *sign );
        // Если дуги с такой меткой нет, тогда создадим её. 
        if( it == node->m_data.end() ) {
            SuffixNode new_node = SuffixNode();
            // Лист? Тогда присвоим ему номер суффикса.
            if( i == suffix.size() - 1 ) {
                new_node.number = number;
            }
            node->m_data[*sign] = new_node;
        }
        node = &(node->m_data[*sign]);
    }
}

void
SuffixTree::CollectPositions( const SuffixNode *node, vec_t &pos ) {
    for( auto const &elem : node->m_data ) {
        if( elem.first == TERMINAL ) {
            pos.push_back( elem.second.number );
        }
        
        CollectPositions( &(elem.second), pos );
    }
}

bool
SuffixTree::Search( const std::string & text, vec_t &pos ) {
    SuffixNode *node = &root;
    for( size_t i = 0; i < text.size(); ++i ) {
        const char *sign = &text[i];
        auto it = node->m_data.find( *sign );
        // Если нет ребра с такой меткой, то текст мы не нашли.
        if( it == node->m_data.end() ) {
            return false;
        }
        node = &(node->m_data[*sign]);

        // Это последний символ? Тогда найдём все позиции в оставшемся
        // поддереве.
        if( i == text.size() - 1 ) {
            CollectPositions( node, pos );
            std::sort( pos.begin(), pos.end() );
        }
    }
    return true;
}

int main() {
    std::string text, pattern;
    std::cin >> pattern;
    SuffixTree root( pattern );
    for( size_t i = 1; std::cin >> text; ++i ) {
        vec_t pos;
        // Образец не встретился в суффиксе.
        if( ! root.Search( text, pos ) ) {
            continue;
        }
        // Пример вывода:
        // 1: 1
        // 2: 2
        // 3: 2, 6
        std::stringstream str;
        const char * delim = ", ";
        // Небольшая хитрость: копируем в поток элементы векторая, чтобы элементы разделялись delim.
        // Если сделать просто std::copy( pos.begin(), pos.end(), ... ), тогда после последнего 
        // элемента будет символ delim. А вообще есть boost::algorithm::join(pos, delim), но его 
        // использовать в лабораторных нельзя!
        std::copy( pos.begin(), pos.end()-1, std::ostream_iterator<size_t>(str, delim) ); 
        std::copy( pos.end()-1, pos.end(), std::ostream_iterator<size_t>(str));
        std::cout << i << ": " << str.str() << std::endl;
    }
    return 0;
}
