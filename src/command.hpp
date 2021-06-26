#pragma once

#include <string>
#include <vector>
#include <functional>

struct Command {
    std::vector<std::string> keys;
    std::function<bool()> function;
    std::string description = "";
    
    Command(std::vector<std::string> keys_, std::function<bool()> function_, std::string description_ = "");
};

static std::vector<Command> commands;

void add_command(Command cmd);

void init_commands();

