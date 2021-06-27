#include "command.hpp"
#include "loop.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "position.hpp"
#include "name.hpp"
#include "inventory.hpp"
#include <iostream>

Command::Command(std::vector<std::string> keys_, std::function<bool()> function_, std::string description_) {
    keys = keys_;
    function = function_;
    description = description_;
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
        },
        "terminates the program"
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
        },
        "prints all visible objects"
    });
    add_command({
        {"help"},
        [](){
            for(auto cmd : commands) {
                std::string msg = "";
                for (auto key : cmd.keys) {
                    msg += key; msg += " ";
                }
                if (cmd.description != "") {
                    msg += "-"; msg += cmd.description;
                }
                msg += "\n";
                std::cout << msg;
            }
            return false;
        },
        "prints all of the possible commands and their descriptions"
    });
    add_command({
        {"inventory", "i"},
        [](){
            auto inventory = player_entity->get_component<Inventory>();
            assert(inventory != nullptr);
            
            std::string msg = "Your items: ";
            for(auto item : inventory->items) {
                auto name = item->owner_ptr->get_component<Name>();
                assert(name != nullptr);
                msg += name->name; msg += " ";
            }
            return false;
        },
        "prints items you currently have"
    });
}
