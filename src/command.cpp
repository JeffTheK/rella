#include "command.hpp"
#include "loop.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "position.hpp"
#include "name.hpp"
#include <iostream>

Command::Command(std::vector<std::string> keys_, std::function<bool()> function_) {
    keys = keys_;
    function = function_;
}

void add_command(Command cmd) {
    commands.push_back(cmd);
}

void init_commands() {
    add_command({
        {"exit", "quit"},
        [](){
            game_is_running = false;
            return false;
        }
    });
    add_command({ // ^
        {"north", "n", "k"},
        [](){
            auto pos = player_entity->get_component<Position>();
            pos->y++;
            return true;
        }
    });
    add_command({
        {"east", "e", "l"},
        [](){
            auto pos = player_entity->get_component<Position>();
            pos->x++;
            return true;
        }
    });
    add_command({
        {"south", "s", "j"},
        [](){
            auto pos = player_entity->get_component<Position>();
            pos->y--;
            return true;
        }
    });
    add_command({
        {"west", "w", "h"},
        [](){
            auto pos = player_entity->get_component<Position>();
            pos->x--;
            return true;
        }
    });
    add_command({
        {"look"},
        [](){
            auto pos = player_entity->get_component<Position>();
            auto func = [pos](Entity& e) -> bool { 
                auto other_pos = *e.get_component<Position>();
                return other_pos == (*pos);
            };
            auto entities = find_entities_if(func);
            if (!entities.empty()) {
                std::string msg = "You see ";
                for(auto e : entities) {
                    auto name = e->get_component<Name>();
                    if (name != nullptr) {
                        msg += name->name; msg += " ";
                    }
                }
                std::cout << msg;
            } else {
                std::cout << "You see nothing";
            }
            return false;
            }
    });
}
