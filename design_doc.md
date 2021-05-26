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
   	id_t get_id() const noexcept { return id; }
    tag_t get_tag() const noexcept { return tag ;}
private:
   	id_t id = 0;
    tag_t tag = "";
}
````

Id

````c++
using id_t = unsigned int;

static id_t free_id = 0;
    
id_t get_free_id() {
	free_id++;
    return free_id;
}
````







## Dev Tools

- Makefile