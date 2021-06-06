#pragma once

#include "../include/json.hpp"
#include "component.hpp"

struct Faction : Component<Faction> {
    enum class Type {
        null,
        player,
        enemy,
        neutral
    };

    Type type = Type::null;

    Faction(Faction::Type type_) {
        type = type_;
    }
    
    static Faction load_from_json(json component_json);
};