#include "map.hpp"
#include "entity.hpp"
#include "terrain.hpp"

void generate_map() {
    for (auto x = 0; x < size_x; x++)
    {
        for (auto y = 0; y < size_y; y++)
        {
            std::string tag = "terrain"; // eg terrain7x12
            tag += std::to_string(x);
            tag += "x";
            tag += std::to_string(y);
            auto e = new Entity{tag};
            e->add_component<Terrain>({Terrain::random()});
            entities.insert({e->get_id(), e});
        }
        
    }
    
}