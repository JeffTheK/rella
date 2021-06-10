#pragma once

#include <string>
#include "../include/json.hpp"
#include "component.hpp"

struct Name : Component<Name> {
    std::string name = "";

    Name(std::string name_) {
        name = name_;
    }
    
    static Name load_from_json(json component_json);
    
    static void load_random_names();
};