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

TEST_CASE("add_component") {
    auto entity = Entity{"foo"};
    entity.add_component<Health>({0,0,0,0});
    CHECK(entity.has_component<Health>());
}

TEST_CASE("remove_component") {
    auto entity = Entity{"foo"};
    entity.add_component<Health>({0,0,0,0});
    entity.remove_component<Health>();
    CHECK_FALSE(entity.has_component<Health>());
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

TEST_CASE("find_entities_if") {
    auto e1 = new Entity{"a"};
    auto e2 = new Entity{"a"};
    auto e3 = new Entity{"b"};
    entities.insert({e1->get_id(), e1});
    entities.insert({e2->get_id(), e2});
    entities.insert({e3->get_id(), e3});
    
    auto func = [](const Entity& e){
        return e.get_tag() == "a";  
    };
    auto result = find_entities_if(func);
    CHECK(result.size() == 2);
    CHECK(result[0] != nullptr);
    CHECK(result[1] != nullptr);
}
