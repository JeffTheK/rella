#pragma once

#include <vector>
#include "component.hpp"
#include "item.hpp"

struct Mana : Component<Mana> {
    unsigned int max_items = 0;
    std::vector<Item> items;

    Mana(unsigned int max_items_) {
      max_items = max_items_;
    }

    Item get_item_by_index(unsigned int index) {
        return items[index];
    }

    unsigned int size() const noexcept { return items.size(); }
};