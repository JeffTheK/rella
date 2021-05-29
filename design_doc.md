

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

  



## Dev Tools

- Makefile
- Doctest