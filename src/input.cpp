#include "input.hpp"
#include "loop.hpp" // game_is_running bool
#include "command.hpp"
#include <iostream>
#include <algorithm>

std::string get_input() {
    std::string str;
    std::cin >> str;
    return str;
}

bool handle_input(std::string input) {
    
    for(auto cmd : commands) {
        auto keys = cmd.keys;
        if (std::find(keys.begin(), keys.end(), input) != keys.end()) {
            return cmd.function();
        }
    }
    
    // command not fund
    auto msg = "command '" + input + "' not found\n";
    std::cout << msg;
    return false;
}
