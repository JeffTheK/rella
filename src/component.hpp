#pragma once

#include "id.hpp"

template<typename DERIVED>
class Component {
public:
    Component() {
        class_id = get_type_id<DERIVED>();
    }

    id_t get_class_id() const noexcept { return class_id; }
private:
	id_t class_id = 0;
};