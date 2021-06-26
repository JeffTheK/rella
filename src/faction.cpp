#include "faction.hpp"
#include <string>
#include "../include/random.hpp"

Faction Faction::random() {
    using Random = effolkronium::random_static;
    auto number = Random::get<int>(2, static_cast<int>(Faction::Type::neutral));
    return static_cast<Faction::Type>(number);
}

Faction Faction::load_from_json(json component_json) {
    auto str = component_json["faction"].get<std::string>();
    auto faction = Faction::Type::null;
    
    if (str == "null") {
        faction = Faction::Type::null;
    } else if (str == "player") {
        faction = Faction::Type::player;
    } else if (str == "enemy") {
        faction = Faction::Type::enemy;
    } else if (str == "neutral") {
        faction = Faction::Type::neutral;
    } else {
        assert(false);
    }

    return Faction{faction};
}
