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
private:
    std::vector<Slot> slots;
};
