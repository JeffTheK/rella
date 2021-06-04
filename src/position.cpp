#include "position.hpp"

Position Position::load_from_json(const json component_json) {
    auto x = component_json["x"].get<unsigned int>();
    auto y = component_json["y"].get<unsigned int>();

    return Position(x, y);
}