#include "../include/doctest.h"
#include "../src/entity.hpp"
#include "../src/health.hpp"
#include "../src/mana.hpp"

TEST_CASE("id") {
    auto entity1 = Entity{"foo"};
    CHECK(entity1.get_id() == 1);
    auto entity2 = Entity{"bar"};
    CHECK(entity2.get_id() == 2);
}

TEST_CASE("has_component") {
    auto entity = Entity{"food"};
    entity.add_component<Health>({0,0,0,0});
    CHECK(entity.has_component<Health>());
    CHECK_FALSE(entity.has_component<Mana>());
}
