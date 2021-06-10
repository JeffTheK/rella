#include "../include/doctest.h"
#include "../src/name.hpp"

TEST_CASE("load_from_json") {
    auto text = R"(
{
    "type": "Name",
    "name": "foo"
}
    )";
  
    auto comp_json = nlohmann::json::parse(text);
    auto comp = Name::load_from_json(comp_json);
    CHECK(comp.name == "foo");
}

TEST_CASE("load_random_names") {
    Name::load_random_names();
}
