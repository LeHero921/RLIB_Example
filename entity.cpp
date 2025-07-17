#include "base.h"
#include "entity.h"
#include "resourceLoader.h"
#include "debug.h"

Entity::Entity(const qTransform& t, const RenderStructure& r, const PhysicsObj& p)
{
    _data = {
        t,
        r,
        p
    };
};

Entity::~Entity()
{
    ;
};

Entity Entity::create_entity(const entityConfig& conf)
{
    Texture2D tex = ResourceLoader::loadResource(conf.texturePath);
    Sprite spr = {
        tex,
        {conf.position.x, conf.position.y, conf.size.x, conf.size.y},
        {0,0, (float)tex.width, (float)tex.height},
    };
    RenderStructure render = { spr, conf.tint };
    qTransform transform = { {0,0}, 0 };
    PhysicsObj pObj = { conf.velocity, conf.mass, conf.speed };

    return Entity(transform, render, pObj);
};

void Entity::load_entity_texture()
{
    Debug::throwNotImplemented();
};

void Entity::remove_entity()
{
    Debug::throwNotImplemented();
};