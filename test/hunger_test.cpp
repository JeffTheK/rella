#include "../include/doctest.h"
#include "../src/hunger.hpp"

TEST_CASE("load_from_json") {
    auto text = R"(
{
    "type": "Health",
    "min": 0,
    "max": 10,
    "current": 10,
    "rate": 1
}
    )";
  
    auto comp_json = nlohmann::json::parse(text);
    auto comp = Hunger::load_from_json(comp_json);
    CHECK(comp.min == 0);
    CHECK(comp.max ==  10);
    CHECK(comp.current == 10);
    CHECK(comp.rate == 1);
}
