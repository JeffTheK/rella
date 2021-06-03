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

TEST_CASE("get_component") {
    auto entity = Entity{"foo"};
    entity.add_component<Health>({10, 10, 10, 10});
    auto comp = entity.get_component<Health>();
    CHECK(comp != nullptr);
    CHECK(comp->current == 10);
    CHECK(entity.get_component<Mana>() == nullptr);
}

TEST_CASE("has_component") {
    auto entity = Entity{"food"};
    entity.add_component<Health>({0,0,0,0});
    CHECK(entity.has_component<Health>());
    CHECK_FALSE(entity.has_component<Mana>());
}
