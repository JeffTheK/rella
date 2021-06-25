#include "command.hpp"

Command::Command(std::string key_, std::function<bool()> function_) {
    key = key_;
    function = function_;
}
