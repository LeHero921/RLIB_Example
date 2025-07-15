#include "base.h"
#include "physics.h"

class Entity
{
public:
    Entity();
    ~Entity();

    Sprite entitySprite;
    bool isPhysicsObj;
    PhysicsObj physicsObj;

    void init_entity(Texture2D* texture);
    void load_entity_texture();
    void remove_entity();
};