#include "command.hpp"
#include "loop.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "position.hpp"
#include "name.hpp"
#include "inventory.hpp"
#include "ai.hpp"
#include "faction.hpp"
#include "health.hpp"
#include "mana.hpp"
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
    add_command({ // FIXME: this code is very shitty, you can inspect yourself(shouldn't do this)
        {"inspect"},
        [](){
            auto player_pos = player_entity->get_component<Position>();
            auto entities = find_entities_if([=](Entity& e){
                auto e_pos = e.get_component<Position>();
                return e_pos != nullptr &&
                    (*e_pos) == (*player_pos) &&
                    e.has_component<AI>();
            });
            
            if (entities.size() == 0) {
                std::cout << "No characters available";
                return false;
            }
            
            std::cout << "Choose which one to inspect";
            std::string msg = "";
            
            for (size_t i = 0; i < entities.size(); i++) {
                auto e = entities[i];
                auto name = e->get_component<Name>();
                assert(name != nullptr);
                msg += std::to_string(i); msg += " - ";
                msg += name->name;
            }
            
            std::string input = "";
            std::cin >> input;
            auto index = std::stoi(input);
            if (index < 0 || index > entities.size() - 1) {
                std::cout << "wrong input";
                return false;
            }
            
            auto entity = entities[index];
            std::string info_msg = "";
            info_msg += entity->get_component<Name>()->name;
            auto faction = entity->get_component<Faction>()->faction;
            if (faction == Faction::Type::enemy) {
                info_msg += " enemy";
            } else if (faction == Faction::Type::neutral) {
                info_msg += " netural";
            } else if (faction == Faction::Type::player) {
                info_msg += " ally";
            }
            auto health = entity->get_component<Health>();
            info_msg += " hp:"; info_msg += std::to_string(health->current); info_msg += "/"; info_msg += std::to_string(health->max);
            auto mana = entity->get_component<Mana>();
            info_msg += " mana:"; info_msg += std::to_string(mana->current); info_msg += "/"; info_msg += std::to_string(mana->max);
            std::cout << info_msg;
            
            return false;
        },
        "print info about selected visible character"
    });
}
