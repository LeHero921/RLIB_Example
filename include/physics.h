#pragma once
#include "entity.h"

typedef struct PhysicsObj
{
    Vector2 velocity;
    float mass;
} PhysicsObj;

class Physics{
public:
    void apply_gravity(PhysicsObj* pObj);
    void apply_velocity(Entity* entity);
};