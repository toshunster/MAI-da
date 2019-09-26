#pragma once

namespace bst {

struct TreeNode {
    char key;
    int value;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode( char _key, char _value ) : key( _key ), value( _value) { }
};

class Tree {
public:
    Tree() {}
    ~Tree() {}
    void Insert( char key, int value );
    void Search( char key );
private:
    void Insert( char key, int value, TreeNode * node );
    void Search( char key, TreeNode * node );
private:
    TreeNode *root = nullptr;
};

} // namespace bst
