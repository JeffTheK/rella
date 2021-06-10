#include "terrain.hpp"
#include "../include/random.hpp"

Terrain Terrain::random() {
    using Random = effolkronium::random_static;
    auto number = Random::get(1, 4); 
    return {static_cast<Terrain::Type>(number)};
}