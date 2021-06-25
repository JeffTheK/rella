#include "command.hpp"
#include "loop.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "position.hpp"

Command::Command(std::string key_, std::function<bool()> function_) {
    key = key_;
    function = function_;
}

void add_command(Command cmd) {
    commands.insert({cmd.key, cmd});
}

void init_commands() {
    add_command({
        "exit",
        [](){
            game_is_running = false;
            return false;
        }
    });
    add_command({ // ^
        "north",
        [](){
            auto pos = player_entity->get_component<Position>();
            pos->y++;
            return true;
        }
    });
}
