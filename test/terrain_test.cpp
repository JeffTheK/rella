#include "../include/doctest.h"
#include "../src/terrain.hpp"

TEST_CASE("random") {
    for (int i = 0; i < 1000; i++)
    {
        auto result = Terrain::random().terrain;
        using terr_enum = Terrain::Type;
        CHECK(result != terr_enum::null);
        CHECK((result == terr_enum::desert || // we need extra () because doctest doesn't like complex
            result == terr_enum::forest ||    // expressions
            result == terr_enum::mountain ||
            result == terr_enum::plains)
        );
    }
}
