#pragma once

using id_t = unsigned int;

id_t get_free_id();

template<typename TYPE>
id_t get_type_id() {
    reinterpret_cast<id_t>(typeid(TYPE).name());
}
