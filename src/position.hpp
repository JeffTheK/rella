#pragma once

#include "component.hpp"

struct Position : Component<Position> {
    Position(unsigned int x_, unsigned int y_) {
        x = x_;
        y = y_;
    }

    unsigned int x = 0;
    unsigned int y = 0;
};