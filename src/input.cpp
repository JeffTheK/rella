#include "input.hpp"
#include "loop.hpp" // game_is_running bool
#include "position.hpp"
#include "player.hpp"
#include "entity.hpp"

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
    }
    else if (input == "north" || input == "n" || input == "k") { // ^
        auto pos = player_entity->get_component<Position>();
        pos->y++;
        return true;
    }
    else if (input == "east" || input == "e" || input == "l") { // -->
        auto pos = player_entity->get_component<Position>();
        pos->x++;
        return true;
    }
    else if (input == "south" || input == "s" || input == "j") { // v
        auto pos = player_entity->get_component<Position>();
        pos->y--;
        return true;
    }
    else {
        auto msg = "command '" + input + "' not found\n";
        std::cout << msg;
        return false;
    }
}
