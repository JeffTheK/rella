#pragma once

#include <vector>
#include "component.hpp"

class Consumable : Component<Consumable> {
public:
    Consumable(std::vector<Component<void>> effects_);
    
    auto get_effects() const noexcept { return effects; }
private:
    std::vector<Component<void>> effects;
};
