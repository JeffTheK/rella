#include "hunger.hpp"

Hunger Hunger::load_from_json(json component_json) {
    auto min = component_json["min"].get<unsigned int>();
    auto max = component_json["max"].get<unsigned int>();
    auto current = component_json["current"].get<unsigned int>();
    auto rate = component_json["rate"].get<unsigned int>();
    
    return Hunger{min, max, current, rate};
}
