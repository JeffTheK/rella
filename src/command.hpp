#pragma once

#include <string>
#include <vector>
#include <functional>

static std::vector<Command> commands;

struct Command {
    std::string key = "";
    std::function<bool()> function;
    
    Command(std::string key_, std::function<bool()> function_);
};