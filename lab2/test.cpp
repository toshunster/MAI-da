#include <iostream>
#include <cassert>
#include <vector>

#include "bst.hpp"

int main()
{
    bst::BST<int64_t, std::string> root;
    std::vector<std::tuple<int64_t, std::string>> records = {
        std::make_tuple(1, "Walter"),
        std::make_tuple(2, "Jesse"),
        std::make_tuple(3, "Saul"),
        std::make_tuple(4, "Mike")
    };
    //! Проверяем, что дерево пустое.
    assert(root.empty());

    for (auto [key, value]: records)
    {
        //! Проверяем, что добавление уникальных
        //! элементов успешно.
        assert(root.insert(key, value));
    }
    //! Теперь дерево не должно быть пустым.
    assert(!root.empty());

    //! Количество узлов должно совпадать с количеством
    //! records.
    assert(root.size() == records.size());

    {
        auto [key, value] = records.back();
        auto [success, found_value] = root.find(key);

        assert( success );
        assert( value == found_value );
    }

    root.clear();
    //! Теперь дерево пустое.
    assert(root.empty());
    //! И мы ничего не найдём больше в нём.
    {
        auto [key, value] = records.back();
        auto [success, found_value] = root.find(key);

        assert( !success );
    }
    return 0;
}
