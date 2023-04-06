#pragma once

#include <tuple>
#include <chrono>
#include <thread>

namespace bst
{

template<typename Key, typename Value>
class BST
{
    struct Node
    {
        Key key;
        Value value;
        Node *left = nullptr;
        Node *right = nullptr;
    };
// Методы.
private:
    bool insert(Node **, const Key, const Value);
    void destroy(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        destroy(node->left);
        destroy(node->right);
        delete node;
        --size_;
    }
public:
    ~BST()
    {
        destroy(root_);
    }

    //! Надо возвращать итератор, а не вот это вот всё.
    bool insert(const Key /*key*/, const Value /*value*/);

    //! Надо возвращать итератор, а не вот это вот всё.
    std::tuple<bool, Value> find(const Key &/*key*/);

    //! Очистка дерева.
    void clear() { destroy(root_); root_ = nullptr; }

    //! Возвращаем количество узлов.
    size_t size() const { return size_; };

    //! Проверяем пустое ли дерево.
    bool empty() const { return size_ == 0; };
// Переменные.
private:
    Node *root_ = nullptr;
    size_t size_ = 0;
};

template<typename Key, typename Value>
bool
BST<Key, Value>::insert(const Key key, const Value value)
{
    return insert(&root_, key, value);
}

template<typename Key, typename Value>
bool
BST<Key, Value>::insert(Node **node, const Key key, const Value value)
{
    if (*node == nullptr)
    {
        *node = new Node(key, value);
        ++size_;
        return true;
    }

    if ((*node)->key == key)
    {
        return false;
    }
    return key < (*node)->key ? insert(&((*node)->left), key, value) : insert(&((*node)->right), key, value);
}

using namespace std::chrono_literals;

template<typename Key, typename Value>
std::tuple<bool, Value>
BST<Key, Value>::find(const Key &key)
{
    Node *node = root_;
    while (node != nullptr)
    {
        if (node->key == key)
        {
            return std::make_tuple(true, node->value);
        }

        node = key < node->key ? node->left : node->right;
    }
    return std::make_tuple(false, Value());
}

}; // namespace bst
