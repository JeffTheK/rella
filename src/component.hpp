#pragma once

#include "id.hpp"

class Entity;

template<typename DERIVED>
class Component {
public:
    Entity* owner_ptr = nullptr;

    Component() {
        class_id = get_type_id<DERIVED>();
    }

    id_t get_class_id() const noexcept { return class_id; }
private:
	id_t class_id = 0;
};