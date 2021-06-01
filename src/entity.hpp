#pragma once

#include <string>
#include <map>
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
    
    template<typename T>
    T* add_component(const T comp) {
        auto comp = components.insert({ comp.class_id(), new T(comp) })
    }
        
   	id_t get_id() const noexcept { return id; }
    tag_t get_tag() const noexcept { return tag ;}
private:
   	id_t id = 0;
    tag_t tag = "";
   	std::map<id_t type_id, Component<void>*> components;
};