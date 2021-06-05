#include "../include/doctest.h"
#include "../src/position.hpp"

TEST_CASE("load_from_json") {
    auto text = R"(
{
    "type": "Position",
    "x": 5,
    "y": 7
}
    )";
  
    auto comp_json = nlohmann::json::parse(text);
    auto pos = Position::load_from_json(comp_json);
    CHECK(pos.x == 5);
    CHECK(pos.y == 7);
}
