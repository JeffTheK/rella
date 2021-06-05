#include "mana.hpp"

Mana Mana::load_from_json(json component_json) {
    auto min = component_json["min"].get<unsigned int>();
    auto max = component_json["max"].get<unsigned int>();
    auto current = component_json["current"].get<unsigned int>();
    auto regen = component_json["regen"].get<unsigned int>();
    
    return Mana{min, max, current, regen};
}
