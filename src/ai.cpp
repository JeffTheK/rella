#include "ai.hpp"
#include "entity.hpp"

void AI::update() {

}

void update_ai() {
    auto ais = find_entities_if([](Entity& e){ return e.get_component<AI>() != nullptr; });
    for(auto ai : ais) {
        auto ai_component = ai->get_component<AI>();
        ai_component->update();
    }
}