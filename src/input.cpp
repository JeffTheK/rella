#include "input.hpp"
#include "loop.hpp" // game_is_running bool

std::string get_input() {
    std::string str;
    std::cin >> str;
    return str;
}

bool handle_input() {
    auto input = get_input();
    
    if (input == "exit" &&
       input == "quit") {
        game_is_running = false;
        return false;
    } else {
        auto msg = "command '" + input + "' not found\n";
        std::cout << msg;
        return false;
    }
}
