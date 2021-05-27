#include "id.hpp"

static id_t free_id = 0;

id_t get_free_id() {
    free_id++;
    return free_id;
}
