#include "../include/doctest.h"
#include "../src/consumable.hpp"

TEST_CASE("load_from_json") {
    auto text = R"(
{
    "type": "Consumable",
    "effects": [
        {
            "type": "Health",
            "min": 0,
            "max": 0,
            "current": 10,
            "regen": 0
        }
    ]
}
    )";
  
    auto comp_json = nlohmann::json::parse(text);
    // auto comp = Consumable::load_from_json(comp_json); FIXME consumabe load from json is not yet implemented
    // auto effects = comp.get_effects(); FIXME this also crashes for some reason
    // CHECK(effects.size() == 1);
}
