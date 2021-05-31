#include "../include/doctest.h"
#include "../src/component.hpp"
#include "../src/health.hpp"
#include "../src/mana.hpp"

TEST_CASE("id") {
    auto health = Health{0, 0, 0, 0};
    auto mana = Mana{0, 0, 0, 0};
    CHECK(health.get_class_id() != mana.get_class_id());

    auto health2 = Health{0, 0, 0, 0};
    CHECK(health.get_class_id() == health2.get_class_id());
}
