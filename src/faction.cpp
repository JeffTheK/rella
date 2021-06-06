#include "faction.hpp"
#include <string>

static Faction load_from_json(json component_json) {
    auto str = component_json["type"].get<std::string>();
    auto type = Faction::Type::null;
    
    if (str == "null") {
        type = Faction::Type::null;
    } else if (str == "player") {
        type = Faction::Type::player;
    } else if (str == "enemy") {
        type = Faction::Type::enemy;
    } else if (str == "neutral") {
        type = Faction::Type::neutral;
    } else {
        assert(false);
    }

    return Faction{type};
}
