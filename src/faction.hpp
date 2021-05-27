#pragma once

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
};