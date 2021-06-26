#include "../include/doctest.h"
#include "../src/faction.hpp"
#include <algorithm>

TEST_CASE("random") {
    auto results = std::vector<Faction::Type>{};
    for (size_t i = 0; i < 1000; i++)
    {
        results.push_back(Faction::random().faction);
    }
    CHECK(std::find_if(results.begin(), results.end(), Faction::Type::enemy) != results.end());
    CHECK(std::find_if(results.begin(), results.end(), Faction::Type::neutral) != results.end());
    
    // should not be present
    CHECK(std::find_if(results.begin(), results.end(), Faction::Type::player) == results.end());
    CHECK(std::find_if(results.begin(), results.end(), Faction::Type::null) == results.end());
}

TEST_CASE("load_from_json") {
    auto text = R"(
{
    "type": "Faction",
    "faction": "player"
}
    )";
  
    auto comp_json = nlohmann::json::parse(text);
    auto comp = Faction::load_from_json(comp_json);
    CHECK(comp.faction == Faction::Type::player);
}
