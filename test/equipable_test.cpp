#include "../include/doctest.h"
#include "../src/equipable.hpp"

TEST_CASE("load_from_json") {
    auto text = R"(
{
    "type": "Equipable",
    "slot": "ring"
}
    )";
  
    auto comp_json = nlohmann::json::parse(text);
    auto comp = Equipable::load_from_json(comp_json);
    auto slot = comp.get_slot();
    CHECK(slot == Equipable::Slot::ring);
}
