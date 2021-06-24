#pragma once

#include "../include/json.hpp"
#include "component.hpp"

struct Position : Component<Position> {
    Position(unsigned int x_, unsigned int y_) {
        x = x_;
        y = y_;
    }

    unsigned int x = 0;
    unsigned int y = 0;
    
    static Position load_from_json(const json component_json);
    
    static Position random();
};