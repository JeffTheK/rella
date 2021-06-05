#include "health.hpp"

Health Health::load_from_json(const json component_json) {
    auto min = component_json["min"].get<unsigned int>();
    auto max = component_json["max"].get<unsigned int>();
    auto current = component_json["current"].get<unsigned int>();
    auto regen = component_json["regen"].get<unsigned int>();
    
    return Health{min, max, current, regen};
}
