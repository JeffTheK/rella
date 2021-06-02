#pragma once

#include <vector>
#include <functional>
#include "component.hpp"
#include "item.hpp"
#include "position.hpp"

struct Inventory : Component<Inventory> {
    unsigned int max_items = 0;
    std::vector<Item*> items;

    Inventory(unsigned int max_items_) {
        max_items = max_items_;
    }

    bool add_item(Item* item) {
        if (this->size() < max_items) {
            items.push_back(item);
            return true;
        }
        else {
            return false;
        }
    }

    void drop_item_by_index(unsigned int index) {
        items.erase(items.begin() + index);
    }

    Item& get_item_by_index(unsigned int index) {
        return *items[index];
    }

    std::vector<Item*> find_if(std::function<bool(const Item&)> func) {
        auto out = std::vector<Item*>{};

        for (auto item_ptr : items) {
            if (func(reinterpret_cast<const Item&>(*item_ptr)) == true) {
                out.push_back(item_ptr);
            }
        }
        return out;
    }

    unsigned int size() const noexcept { return items.size(); }
};