#include <iostream>

namespace trie {

const int ALPHABET_SIZE = 26;

struct TrieNode {
    bool isLeaf = false;

    TrieNode* childs[ALPHABET_SIZE];
    // Для экономии памяти лучше использовать
    // std::unordered_map<TrieNode*> childs;
    TrieNode();
};

class Trie {
private:
    TrieNode *root = nullptr;
public:
    Trie();
    ~Trie();
    
    // Вставляем слово. Если оно уже есть, тогда
    // вернём false, иначе - true.
    bool insert(const std::string &str);

    // Существует ли такое слово.
    bool find(const std::string &str);

    // Существует ли такой префикс.
    bool startsWith(const std::string &str);

    // TODO: реализовать как-нибудь.
    // bool delete(const std::string &str);
private:
    // Удаляем рекурсивно все узлы дерева.
    void destroyRecursive( TrieNode* node );
};

} // namespace trie
