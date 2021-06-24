#include "map.hpp"
#include "player.hpp"
#include "loop.hpp"

int main(int argc, char const *argv[])
{
    generate_map();
    generate_player();
    start_loop();
    return 0;
}
