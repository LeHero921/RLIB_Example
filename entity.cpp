#include "base.h"
#include "entity.h"
#include "debug.h"

Entity::Entity(const qTransform& t, const RenderStructure& r, const PhysicsObj& p)
{
    init_entity(t, r ,p);
};

Entity::~Entity()
{
    ;
};

void Entity::init_entity(const qTransform& t, const RenderStructure& r, const PhysicsObj& p)
{
    Debug::log("[Entity] Initializing entity!");
    _data = {
        t,
        r,
        p
    };
};

void Entity::load_entity_texture()
{
    ;
};

void Entity::remove_entity()
{
    ;
};