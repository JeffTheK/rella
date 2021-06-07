#pragma once

#include <vector>
#include "../include/json.hpp"
#include "component.hpp"

class Consumable : Component<Consumable> {
public:
    Consumable(std::vector<Component<void>> effects_);
    
    auto get_effects() const noexcept { return effects; }
    
    static Consumable load_from_json(json component_json);
private:
    std::vector<Component<void>> effects;
};
