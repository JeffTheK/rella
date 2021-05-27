#pragma once

#include <string>
#include "component.hpp"

struct Name : Component<Name> {
    std::string name = "";

    Name(std::string name_) {
        name = name_;
    }
};