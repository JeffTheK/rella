#pragma once

#include <vector>
#include <functional>
#include "component.hpp"
#include "item.hpp"

struct Inventory : Component<Inventory> {
    unsigned int max_items = 0;
    std::vector<Item> items;

    Inventory(unsigned int max_items_) {
        max_items = max_items_;
    }

    bool add_item(Item item) {
        if (size() < max_items) {
            items.push_back(item);
            return true;
        }
        else {
            return false;
        }
    }

    Item get_item_by_index(unsigned int index) {
        return items[index];
    }

    std::vector<Item*> find_if(std::function<true(const Item&)> func) {
        auto out = std::vector;

        for (const auto& item : items) {
            if (func(item) == true) {
                out.push_back(item);
            }
        }
        return out; 
    }

    unsigned int size() const noexcept { return items.size(); }
};