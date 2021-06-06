#include "name.hpp"

Name Name::load_from_json(json component_json) {
    auto name = component_json["name"].get<std::string>();
    
    return Name{name};
}
