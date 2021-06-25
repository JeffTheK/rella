#pragma once

#include <string>
#include <map>
#include <functional>

struct Command {
    std::string key = "";
    std::function<bool()> function;
    
    Command(std::string key_, std::function<bool()> function_);
};

static std::map<std::string, Command> commands;

void add_command(Command cmd);

void init_commands();

