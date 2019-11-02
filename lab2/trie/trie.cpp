#include "trie.hpp"

namespace trie {

TrieNode::TrieNode() {
    for( size_t i = 0; i < ALPHABET_SIZE; ++i ) {   
        childs[i] = nullptr;
    }
}

Trie::Trie()
{
    root = new TrieNode();
}

void Trie::destroyRecursive(TrieNode* node)
{
    if( node ) {
        for( size_t i = 0; i < ALPHABET_SIZE; ++i ) {
            if( node->childs[i] ) {
                destroyRecursive( node->childs[i] );
            }
        }
        delete node;
    }
}

Trie::~Trie()
{
    destroyRecursive( root );
}

bool Trie::insert( const std::string &str ) {
    TrieNode *node = root;
    bool hasSameText = true;
    for( char ch : str ) {
        size_t ch_idx = ch - 'a';

        if( node->childs[ch_idx] == nullptr ) {
            node->childs[ch_idx] = new TrieNode();
            // Если мы не создали ни одного нового
            // узла, тогда это звоночек, что такой
            // узел уже есть.
            hasSameText = false;
        }
        node = node->childs[ch_idx];
    }
    // Успешно вставили в Trie ->
    // 1) Если мы создали хотя бы один узел;
    // 2) или str это префикс существующего слова
    //    то есть isLeaf был false.
    bool wasLeaf = node->isLeaf;
    node->isLeaf = true;
    return !hasSameText || !wasLeaf;
}

bool Trie::find( const std::string &str ) {
    TrieNode *node = root;
    for( char ch : str ) {
        size_t ch_idx = ch - 'a';
        if( !node->childs[ch_idx] ) {
            return false;
        }
        node = node->childs[ch_idx];
    }
    return node->isLeaf;
}

bool Trie::startsWith( const std::string &str ) {
    TrieNode *node = root;
    for( char ch : str ) {
        size_t ch_idx = ch - 'a';
        if( !node->childs[ch_idx] ) {
            return false;
        }
        node = node->childs[ch_idx];
    }
    return true;
}

} // namespace trie
