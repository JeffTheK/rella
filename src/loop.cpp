#include "loop.hpp"
#include "input.hpp"

void loop() {
    auto result = handle_input(); // returns bool
    // if true player made action/took turn and now we need to update ai
    // else return and loop again
    if (result != true) return;

    update_ai();
}