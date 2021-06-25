#include "loop.hpp"
#include "input.hpp"
#include "ai.hpp"

void start_loop() {
    while (game_is_running == true) {
        loop();
    }
}

void loop() {
    auto result = handle_input(get_input()); // returns bool
    // if true player made action/took turn and now we need to update ai
    // else return and loop again
    if (result != true) return;

    update_ai();
}