#include "../include/doctest.h"
#include "../src/damage.hpp"

TEST_CASE("load_from_json") {
    auto text = R"(
{
    "type": "Damage",
    "min": 1,
    "max": 5
}
    )";
  
    auto comp_json = nlohmann::json::parse(text);
    auto comp = Damage::load_from_json(comp_json);
    CHECK(comp.min == 1);
    CHECK(comp.max == 5);
}
