#pragma once

#include "component.hpp"

struct Hunger : Component<Hunger> {
    unsigned int min = 0;
    unsigned int max = 0;
    unsigned int current = 0;
    unsigned int rate = 0;

    Hunger(unsigned int min_, unsigned int max_, unsigned int current_, unsigned int rate_) {
        min = min_;
        max = max_;
        current = current_;
        rate = rate_;
    }
};