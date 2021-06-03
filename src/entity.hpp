#pragma once

#include <string>
#include <map>
#include <algorithm>
#include "id.hpp"
#include "component.hpp"

using tag_t = std::string;

// The entity is a general purpose object that represents our player, enemies items.
class Entity {
public:
    Entity(tag_t tag_) {
        tag = tag_;
        id = get_free_id();
    }
    
    template<typename T>
    T* add_component(const T comp) {
        auto result = components.insert({ comp.class_id(), new T(comp) });
    }
    
    template<typename T>
    void remove_component() {
        auto result = std::find_if(components.begin(), components.end(),
        [](Component<void>* comp){ comp->class_id() == get_type_id<T>(); }
        );

        if (result != components.end()) {
            delete result;
            components.erase(result);
        }
    }
        
   	id_t get_id() const noexcept { return id; }
    tag_t get_tag() const noexcept { return tag ;}
private:
   	id_t id = 0;
    tag_t tag = "";
   	std::map<id_t, Component<void>*> components;
};