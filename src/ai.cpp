#include "ai.hpp"
#include "entity.hpp"
#include "faction.hpp"

void AI::update() {
    assert(owner_ptr->has_component<Faction>());
    auto faction = owner_ptr->get_component<Faction>()->faction;
    
    if (faction == Faction::Type::player) {
        update_player();
    } else if (faction == Faction::Type::neutral) {
        update_neutral();
    } else if (faction == Faction::Type::enemy) {
        update_enemy();
    } else {
        assert(false);
    }
}

void AI::update_player() {

}
void AI::update_neutral() {

}
void AI::update_enemy() {

}


void update_ai() {
    auto ais = find_entities_if([](Entity& e){ return e.get_component<AI>() != nullptr; });
    for(auto ai : ais) {
        auto ai_component = ai->get_component<AI>();
        ai_component->update();
    }
}