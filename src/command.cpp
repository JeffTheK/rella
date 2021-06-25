#include "command.hpp"
#include "loop.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "position.hpp"

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
}
