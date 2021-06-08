#pragma once

#include <vector>
#include "../include/json.hpp"
#include "component.hpp"

class Equipable : Component<Equipable> {
public:

    enum class Slot {
      null,
      armor,
      weapon,
      ring
    };

    Equipable(std::vector<Equipable::Slot> slots_);
    
    auto get_slots() const noexcept { return slots; }
    
    static Equipable load_from_json(json component_json);
private:
    std::vector<Slot> slots;
};
