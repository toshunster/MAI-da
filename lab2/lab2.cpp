#include <iostream>

struct Node {
    char key;
    int value;
    Node *left = nullptr;
    Node *right = nullptr;

    Node( char _key, char _value ) : key( _key ), value( _value) { }
};

class Tree {
public:
    Tree() {}
    ~Tree() {}
    void Insert( char key, int value );
    void Search( char key );
private:
    void Insert( char key, int value, Node * node );
    void Search( char key, Node * node );
private:
    Node *root;
};

void
Tree::Insert( char key, int value )
{
    if( root == nullptr )
    {
        root = new Node( key, value );
        std::cout << "OK" << std::endl;
        return;
    }

    Insert( key, value, root );
}

void
Tree::Insert( char key, int value, Node *node )
{
    if( node == nullptr )
    {
        node = new Node( key, value );
        std::cout << "OK" << std::endl;
        return;
    }

    if( node->key == key )
    {
        std::cout << "Exists" << std::endl;
        return;
    }

    if( key < node->key && node->left == nullptr )
    {
        node->left = new Node( key, value );
        std::cout << "OK" << std::endl;
        return;
    }

    if( key > node->key && node->right == nullptr )
    {
        node->right = new Node( key, value );
        std::cout << "OK" << std::endl;
        return;
    }

    Insert( key, value, key < node->key ? node->left : node->right );
}

void
Tree::Search( char key )
{
    Search( key, root );
}

void
Tree::Search( char key, Node * node )
{
    if( node == nullptr )
    {
        std::cout << "NoSuchWord" << std::endl;
        return;
    }

    if( key == node->key )
    {
        std::cout << "OK: " << node->value << std::endl;
        return;
    }

    Search( key, key < node->key ? node->left : node->right );
}

int main()
{
    Tree root;
    char key;
    int value;
    char action;
    while( std::cin >> action )
    {
        // Операция добавления,...
        if( action == '+' )
        {
            std::cin >> key >> value;
            root.Insert( tolower( key ), value );
        }
        // другие else if
        // ...
        // иначе поиск.
        else
        {
            // В качестве ключа выступает тут action.
            char key = tolower( action );
            root.Search( key );
        }
    }

    return 0;
}
