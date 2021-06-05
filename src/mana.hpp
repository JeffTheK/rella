#pragma once

#include "../include/json.hpp"
#include "component.hpp"

struct Mana : Component<Mana> {
    unsigned int min = 0;
    unsigned int max = 0;
    unsigned int current = 0;
    unsigned int regen = 0;

    Mana(unsigned int min_, unsigned int max_, unsigned int current_, unsigned int regen_) {
        min = min_;
        max = max_;
        current = current_;
        regen = regen_;
    }
    
    static Mana load_from_json(json component_json);
};