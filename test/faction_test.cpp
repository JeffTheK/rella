#include "../include/doctest.h"
#include "../src/faction.hpp"

TEST_CASE("") {

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
