

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
- [ ] Name
- [ ] Faction
- [ ] Consumable
- [ ] Damage
- [ ] Equipable



## Json Loading Tests

- [x] Position
- [x] Health
- [x] Mana
- [x] Hunger
- [ ] Name
- [ ] Faction
- [ ] Consumable
- [ ] Damage
- [ ] Equipable



## Rake Tasks

`rake debug` - compiles debug build

`rake release` - compiles release build

`rake test` - compiles a unit test exe and runs it

`rake add_class` - creates a class in /src/ from a template

`rake add_test` - creates test case in /test/ from a template



## Runtime libraries

- Nlohmann Json



## Dev Tools

- Rake
- Doctest

