#pragma once
#include "base.h"
#include "physics.h"

struct entityData
{
    qTransform transform;
    RenderStructure renderer;
    PhysicsObj physicsObj;
};


class Entity
{
public:
    Entity(const qTransform& t, const RenderStructure& r, const PhysicsObj& p);
    ~Entity();

    entityData _data;

    void init_entity(const qTransform& t, const RenderStructure& r, const PhysicsObj& p);
    void load_entity_texture();
    void remove_entity();
};