#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "../src/id.hpp"

TEST_CASE("get_free_id") {
    CHECK(get_free_id() == 1);
    CHECK(get_free_id() == 2);
}
