#pragma once

#include "component.hpp"

class AI : Component<AI> {
public:
    void update();
private:
};

void update_ai();