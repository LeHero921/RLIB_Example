#pragma once
#include "base.h"

typedef struct PhysicsObj
{
    Vector2 velocity;
    float mass;
} PhysicsObj;

class Physics{
public:
    void apply_gravity(PhysicsObj* pObj);
};