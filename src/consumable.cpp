#include "consumable.hpp"

Consumable::Consumable(std::vector<Component<void>> effects_) {
    effects = effects_;
}

Consumable Consumable::load_from_json(json component_json) {
    auto effects_json = component_json["effects"];
    // auto effects = load_components_from_json(effects_json);
    assert(false); // FIXME implement load_components_from_json so that we can get effects

    return Consumable{{}}; // also FIXME
}

