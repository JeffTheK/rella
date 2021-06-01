#pragma once

#include <typeinfo>

using id_t = unsigned int;

id_t get_free_id();

void reset_free_id();

template<typename TYPE>
id_t get_type_id() {
    return static_cast<id_t>(typeid(TYPE).hash_code());
}
