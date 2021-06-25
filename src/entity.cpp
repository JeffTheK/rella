#include "entity.hpp"

std::vector<Entity*> find_entities_if(std::function<bool(const Entity&)> func) {
    auto out = std::vector<Entity*>{};
    for (const auto key_value : entities) {
        const auto entity = key_value.second;
        if (func(*entity) == true) {
            out.push_back(entity);
        }
    }
    
    return out;
}