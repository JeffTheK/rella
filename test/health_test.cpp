#include "../include/doctest.h"
#include "../src/health.hpp"

TEST_CASE("load_from_json") {
    auto text = R"(
{
    "type": "Health",
    "min": 0,
    "max": 10,
    "current": 10,
    "regen": 1
}
    )";
  
    auto comp_json = nlohmann::json::parse(text);
    auto comp = Health::load_from_json(comp_json);
    CHECK(comp.min == 0);
    CHECK(comp.max ==  10);
    CHECK(comp.current == 10);
    CHECK(comp.regen == 1);
}
