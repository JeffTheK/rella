

# Design Doc



## ECS

Entity component system

````c++
// The entity is a general purpose object that represents our player, enemies items.
class Entity {
public:
    Entity(tag_) {
        tag = tag_
        id = rella::get_free_id()
    }
    
    template<typename T>
    Component& add_component(Component comp) {
        components.push_back(std::make_unique<T>(comp))
    }
    
    template<typename T>
    void remove_component() {
       	// remove component if found
    }
    
    template<typename T>
    T* get_component() {
        // return pointer to T if found of type T
        // else return nullptr
    }
    
    template<typename T>
    bool has_component() {
        // return true if component and false if not
    }
        
   	id_t get_id() const noexcept { return id; }
    tag_t get_tag() const noexcept { return tag ;}
private:
   	id_t id = 0;
    tag_t tag = "";
   	std::vector<Component<void>*> components;
}
````

- [x] Id


````c++
using id_t = unsigned int;

static id_t free_id = 0;
    
id_t get_free_id() {
	free_id++;
    return free_id;
}

void reset_free_id() {
    free_id = 0;
}

template<typename TYPE>
id_t get_type_id() {
    reinterpret_cast<id_t>(typeid(TYPE).name());
}
````

- [x] Component


````c++
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
}
````



## Json loading components

`load_json_components(json components_json)` - loads components from json

````c++
std::vector<Components<void>> load_json_components(json components_json) {
    // get type of component
    // iterate over each json component
    switch(type) {
    case "Health":
    	Health::load_from_json(json_component);
    case "Mana":
		Mana::load_from_json(json_component);
    default:
        assert(false);
    }
}
````





## Json items structure

````json
{
    "items": [
        {
			"components": [
                {
                    "type": "Health",
                    "min": 0,
                    "max": 10,
                    "current": 10,
                    "regen": 1
                }
            ]
        },
        {
            "components": [
                {
                    "type": "Mana",
                    "min": 0,
                    "max": 10,
                    "current": 10,
                    "regen": 1
                }
            ]
        }
    ]
}
````





## Main

````c++
int main() {
    generate_map();
    generate_player();
    generate_ai();
   	
    while(game_is_running == true) {
        loop();
    }
}
````

- [x] generate_map() - const size_x, size_y, generates terrains



- [x] ## Loop


````c++
static bool game_is_running = true;

void loop() {
    auto result = handle_input(); // returns bool
    // if true player made action/took turn and now we need to update ai
    // else return and loop again
    if (result != true) return;
    
    update_ai();
}
````



- [x] ##  Input Handling


````c++
std::string get_input() {
    // returns input
}

// returns true if player made action that will end hit turn and require to update ai
bool handle_input() {
 	auto input = get_input();
    
    if (input == "exit" &&
       input == "quit") {
        game_is_running = false;
        return false;
    } else if (input == "some_command") {
        // ...
    } else {
        // command not found
        // warn player
        return false;
    }
}
````



- [x] ##  Player Generation


````c++
void generate_player() {
    // create entity
    // add random position
    // add inventory with random starting items
    // add random name
    // add player faction
    // add hunger
    // add health
    // add mana
    // add entity to container
    // set player_entity to pointer
}
````



## Name

- [x] random() - returns random picked name from templates (if templates are empty load them) they are stored in data/names.json	



## Player Commands

- [x] quit, exit - terminates the program( sets game_is_running to false)
- [x] help - prints all commands and descriptions
- [x] north,  n, k - move ^
- [x] east,   e  l- move -->
- [x] south, s   j - move v
- [x] west,  w  h- move <--
- [x] pickup - take item on the ground. If multiple items make list
- [x] drop - creates a list of items player has with indexes and drops item by index or types something else to quit
- [ ] attack, a - choose enemy to attack
- [x] inventory, i - prints items player has
- [x] inspect - makes a list of npcs to enspect. Upon choosing prints their info like stats, health, faction
- [x] look - lists all objects that are on the same position as player



## Components that we need

- [x] Position - x, y
- [x] Health - min, max, current, regen
- [x] Mana - min, max,  current, regen
- [x] Hunger - min, max, current, rate
- [x] Damage - min, max
- [x] Name - name
- [ ] EnemyAI
- [x] Faction - faction (player, enemy, neutral)
- [x] Inventory - max_items, items, size(), get_item_by_index(), find_item(), add_item()
- [x] Item
- [x] Consumable - has a list of components that affect holder upon usage
- [x] Equipable - slot enum, slots
- [x] Terrain - terrain, types: null, forest, mountain, plains, desert, random()




## Unit Tests

- [x] Entity
  - [x] add_component()
  - [x] remove_component()
  - [x] get_component()
  - [x] has_component()
- [x] Id
  - [x] get_free_id()
  - [x] get_type_id()
  - [x] reset_free_id()
- [x] Component
  - [x] check id
- [ ] Inventory
  - [x] size()
  - [ ] get_item_by_index()
  - [ ] drop_item_by_index()
  - [ ] find_if()
  - [ ] add_item()



## Json Loading

- [x] Position
- [x] Health
- [x] Mana
- [x] Hunger
- [x] Name
- [x] Faction
- [ ] Consumable - FIXME
- [x] Damage
- [x] Equipable



## Json Loading Tests

- [x] Position
- [x] Health
- [x] Mana
- [x] Hunger
- [x] Name
- [x] Faction
- [ ] Consumable - FIXME
- [x] Damage
- [x] Equipable



## Rake Tasks

`rake debug` - compiles debug build

`rake release` - compiles release build

`rake test` - compiles a unit test exe and runs it

`rake add_class` - creates a class in /src/ from a template

`rake add_test` - creates test case in /test/ from a template



## Runtime libraries

- [nlohmann](https://github.com/nlohmann)/**[json](https://github.com/nlohmann/json)** - for json
- [effolkronium](https://github.com/effolkronium)/**[random](https://github.com/effolkronium/random)** - for random number generation



## Dev Tools

- Rake
- [onqtam](https://github.com/onqtam)/**[doctest](https://github.com/onqtam/doctest)** - for unit testing

