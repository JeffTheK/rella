#pragma once

#include "component.hpp"

class AI : Component<AI> {
public:
    void update();
private:
    void update_player();
    void update_neutral();
    void update_enemy();
};

void update_ai();