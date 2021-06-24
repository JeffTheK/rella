#include "player.hpp"
#include "entity.hpp"
#include "position.hpp"
#include "inventory.hpp"
#include "name.hpp"
#include "faction.hpp"
#include "hunger.hpp"
#include "health.hpp"
#include "mana.hpp"

void generate_player() {
    const auto max_items = 30;
    const auto max_hunger = 100;
    const auto hunger_rate = 1;
    const auto max_health = 10;
    const auto health_regen = 1;
    const auto max_mana = 5;
    const auto mana_regen = 1;

    auto entity = new Entity{"player"};
    entity->add_component<Position>(Position::random());
    entity->add_component<Inventory>({max_items});
    entity->add_component<Name>(Name::random());
    entity->add_component<Faction>({Faction::Type::player});
    entity->add_component<Hunger>({0, max_hunger, max_hunger, hunger_rate});
    entity->add_component<Health>({0, max_health, max_health, health_regen});
    entity->add_component<Mana>({0, max_mana, max_mana, mana_regen});
    entities.insert({entity->get_id(), entity});
    player_entity = entity;
}
