#include "command.hpp"

Command::Command(std::string key_, std::function<bool()> function_) {
    key = key_;
    function = function_;
}

void add_command(Command cmd) {
    commands.insert({cmd.key, cmd});
}
