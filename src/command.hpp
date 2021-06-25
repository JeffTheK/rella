#pragma once

#include <string>
#include <vector>
#include <functional>

struct Command {
    std::string key = "";
    std::function<bool()> function;
    
    Command(std::string key_, std::function<bool()> function_);
};