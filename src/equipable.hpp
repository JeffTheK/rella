#pragma once

#include <vector>
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
private:
    std::vector<Slot> slots;
};
