#include "damage.hpp"

Damage Damage::load_from_json(json component_json) {
    auto min = component_json["min"].get<unsigned int>();
    auto max = component_json["max"].get<unsigned int>();

    return Damage{min, max};
}
