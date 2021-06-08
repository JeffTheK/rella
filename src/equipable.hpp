#pragma once

#include "../include/json.hpp"
#include "component.hpp"

struct Equipable : Component<Equipable> {
public:
    enum class Slot {
      null,
      armor,
      weapon,
      ring
    };

    Equipable(Equipable::Slot slot_);
    
    auto get_slot() const noexcept { return slot; }
    
    static Equipable load_from_json(json component_json);
private:
    Slot slot;
};
