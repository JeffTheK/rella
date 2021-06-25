#pragma once

#include <string>
#include <map>
#include <functional>

static std::map<std::string, Command> commands;

struct Command {
    std::string key = "";
    std::function<bool()> function;
    
    Command(std::string key_, std::function<bool()> function_);
};

void add_command(Command cmd);

