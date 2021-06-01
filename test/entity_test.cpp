#include "../include/doctest.h"
#include "../src/entity.hpp"

TEST_CASE("id") {
    auto entity1 = Entity{"foo"};
    CHECK(entity1.get_id() == 1);
    auto entity2 = Entity{"bar"};
    CHECK(entity2.get_id() == 2);
}
