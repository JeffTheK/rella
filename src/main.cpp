#include "map.hpp"
#include "player.hpp"
#include "loop.hpp"
#include "command.hpp"
#include "npc.hpp"

int main(int argc, char const *argv[])
{
    init_commands();
    generate_map();
    generate_player();
    generate_npcs();
    start_loop();
    return 0;
}
