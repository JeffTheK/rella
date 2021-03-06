#include "npc.hpp"
#include "entity.hpp"
#include "position.hpp"
#include "inventory.hpp"
#include "name.hpp"
#include "faction.hpp"
#include "health.hpp"
#include "mana.hpp"
#include "../include/random.hpp"

void make_random_npc() {
    const auto max_items = 30;
    const auto max_health = 10;
    const auto health_regen = 1;
    const auto max_mana = 5;
    const auto mana_regen = 1;   

    auto entity = new Entity{"npc"};
    entity->add_component<Position>(Position::random());
    entity->add_component<Inventory>({max_items});
    entity->add_component<Name>(Name::random());
    entity->add_component<Faction>({Faction::random()});
    entity->add_component<Health>({0, max_health, max_health, health_regen});
    entity->add_component<Mana>({0, max_mana, max_mana, mana_regen});
    entities.insert({entity->get_id(), entity});
}

void generate_npcs() {
    const unsigned int min_count = 10;
    const unsigned int max_count = 20;
    
    using Random = effolkronium::random_static;
    auto count = Random::get<unsigned int>(min_count, max_count);
    for (unsigned int i = 0; i < count; i++)
    {
        make_random_npc();
    }
}