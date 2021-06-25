#pragma once

#include <string>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>
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
        auto ptr = new T(comp);
        auto result = components.insert({ comp.get_class_id(), reinterpret_cast<Component<void>*>(ptr) });
        return ptr;
    }
    
    template<typename T>
    void remove_component() {
        auto result = components.find(get_type_id<T>());

        if (result != components.end()) {
            delete result->second;
            components.erase(result);
        }
    }
    
    template<typename T>
    T* get_component() {
        auto result = components.find(get_type_id<T>());
        
        if (result != components.end()) {
            auto ptr = result->second;
            return reinterpret_cast<T*>(ptr);
        } else {
            return nullptr;
        }
    }
    
    template<typename T>
    bool has_component() {
        auto result = components.find(get_type_id<T>());
        
        return result != components.end();
    }
        
   	id_t get_id() const noexcept { return id; }
    tag_t get_tag() const noexcept { return tag ;}
private:
   	id_t id = 0;
    tag_t tag = "";
   	std::map<id_t, Component<void>*> components;
};

static std::map<id_t, Entity*> entities; // Holds all our entities

static Entity* player_entity = nullptr;

// note: I couldn't make entity& const
std::vector<Entity*> find_entities_if(std::function<bool(Entity&)> func);