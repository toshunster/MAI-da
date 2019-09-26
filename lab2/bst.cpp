#include <iostream>

#include "bst.hpp"

namespace bst {

void
Tree::Insert( char key, int value ) {
    // Если дерево пустое, тогда создадим корень.
    if( root == nullptr ) {
        root = new TreeNode( key, value );
        std::cout << "OK" << std::endl;
        return;
    }
    // Иначе -- добавим в дерево.
    Insert( key, value, root );
}

void
Tree::Insert( char key, int value, TreeNode *node ) {
    if( node == nullptr ) {
        node = new TreeNode( key, value );
        std::cout << "OK" << std::endl;
        return;
    }

    if( node->key == key ) {
        std::cout << "Exists" << std::endl;
        return;
    }

    if( key < node->key && node->left == nullptr ) {
        node->left = new TreeNode( key, value );
        std::cout << "OK" << std::endl;
        return;
    }

    if( key > node->key && node->right == nullptr ) {
        node->right = new TreeNode( key, value );
        std::cout << "OK" << std::endl;
        return;
    }

    Insert( key, value, key < node->key ? node->left : node->right );
}

void
Tree::Search( char key ) {
    Search( key, root );
}

void
Tree::Search( char key, TreeNode *node ) {
    if( node == nullptr ) {
        std::cout << "NoSuchWord" << std::endl;
        return;
    }

    if( key == node->key ) {
        std::cout << "OK: " << node->value << std::endl;
        return;
    }

    Search( key, key < node->key ? node->left : node->right );
}

} // namespace bst
