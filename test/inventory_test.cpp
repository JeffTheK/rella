#include "../include/doctest.h"
#include "../src/inventory.hpp"

TEST_CASE("size") {
    auto inv = Inventory{10};
    CHECK(inv.size() == 0);
    
    inv.add_item({});
    CHECK(inv.size() == 1);
}

TEST_CASE("add_item") {
    auto inv = Inventory{1};
    inv.add_item({});
    CHECK(inv.size() == 1);
    inv.add_item({});
    CHECK(inv.size() == 1);
}