#include "map.hpp"
#include "entity.hpp"
#include "terrain.hpp"

void generate_map() {
    for (unsigned int x = 0; x < map::size_x; x++)
    {
        for (unsigned int y = 0; y < map::size_y; y++)
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