#pragma once

#include "../include/json.hpp"
#include "component.hpp"

struct Damage : Component<Damage> {
    unsigned int min = 0;
    unsigned int max = 0;

    Damage(unsigned int min_, unsigned int max_) {
        min = min_;
        max = max_;
    }
    
    static Damage load_from_json(json component_json);
};