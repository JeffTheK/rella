#include "../include/doctest.h"
#include "../src/id.hpp"

TEST_CASE("get_free_id") {
    reset_free_id();
    CHECK(get_free_id() == 1);
    CHECK(get_free_id() == 2);
}

TEST_CASE("get_type_id") {
    CHECK(get_type_id<int>() != get_type_id<char>());
}

TEST_CASE("reset_free_id") {
    reset_free_id();
    CHECK(get_free_id() == 1);
    reset_free_id();
    CHECK(get_free_id() == 1);
}
