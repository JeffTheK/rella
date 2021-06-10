#pragma once

#include "component.hpp"

struct Terrain : Component<Terrain> {
public:
    enum class Type {
        null,
        forest,
        mountain,
        plains,
        desert
    };

    const Type terrain = Type::null;
    
    Terrain(Terrain::Type terrain_) : terrain(terrain_) {}
};
