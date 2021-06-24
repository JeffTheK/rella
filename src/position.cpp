#include "position.hpp"
#include "../include/random.hpp"
#include "map.hpp"

Position Position::load_from_json(const json component_json) {
    auto x = component_json["x"].get<unsigned int>();
    auto y = component_json["y"].get<unsigned int>();

    return Position(x, y);
}

Position Position::random() {
    using Random = effolkronium::random_static;
    auto x = Random::get<unsigned int>(0, map::size_x);
    auto y = Random::get<unsigned int>(0, map::size_y);
    return Position{x, y};
}