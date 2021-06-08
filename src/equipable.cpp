#include "equipable.hpp"

Equipable::Equipable(Equipable::Slot slot_) {
    slot = slot_;
}

Equipable Equipable::load_from_json(json component_json) {
    auto str = component_json["slot"].get<std::string>();
    auto slot = Equipable::Slot::null;
    if (str == "null") {
        slot = Equipable::Slot::null;
    } else if (str == "armor") {
        slot = Equipable::Slot::armor;
    } else if (str == "weapon") {
        slot = Equipable::Slot::weapon;
    } else if (str == "ring") {
        slot = Equipable::Slot::ring;
    } else {
        assert(false); // FIXME? maybe add assert message or throw exception?
    }

    return Equipable{slot};
}

