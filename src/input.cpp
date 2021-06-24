#include "input.hpp"
#include "loop.hpp" // game_is_running bool
#include "position.hpp"
#include "player.hpp"
#include "entity.hpp"
#include "name.hpp"

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
    else if (input == "west" || input == "w" || input == "h") { // <--
        auto pos = player_entity->get_component<Position>();
        pos->x--;
        return true;
    }
    else if (input == "look") {
        auto pos = player_entity->get_component<Position>();
        auto func = [pos](Entity& e) -> bool { 
            auto other_pos = e.get_component<Position>();
            return other_pos* == pos*;
        };
        auto entities = find_entities_if(func);
        if (!entities.empty())
            std::string msg = "You see ";
            for(auto e : entities) {
                auto name = e->get_component<Name>();
                if (name != nullptr) {
                    msg += name.name; msg += " ";
                }
            }
            std::cout << msg;
        } else {
            std::cout << "You see nothing";
        }
        return false;
    }
    else {
        auto msg = "command '" + input + "' not found\n";
        std::cout << msg;
        return false;
    }
}
