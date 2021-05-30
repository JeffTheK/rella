#pragma once

#include <string>
#include <vector>
#include "id.hpp"
#include "component.hpp"

using tag_t = std::string;

// The entity is a general purpose object that represents our player, enemies items.
class Entity {
public:
    Entity(tag_t tag_, id_t id) {
        tag = tag_;
        id = get_free_id();
    }
        
   	id_t get_id() const noexcept { return id; }
    tag_t get_tag() const noexcept { return tag ;}
private:
   	id_t id = 0;
    tag_t tag = "";
   	std::vector<Component<void>*> components;
};