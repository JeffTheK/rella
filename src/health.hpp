#pragma once

#include "component.hpp"

struct Health : Component<Health> {
    unsigned int min = 0;
    unsigned int max = 0;
    unsigned int current = 0;
    unsigned int regen = 0;

    Health(unsigned int min_, unsigned int max_, unsigned int current_, unsigned int regen_) {
        min = min_;
        max = max_;
        current = current_;
        regen = regen_;
    }
};