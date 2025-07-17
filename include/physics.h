#pragma once
#include "base.h"

typedef struct PhysicsObj
{
    Vector2 velocity;
    float mass;
    Vector2 direction;
    float speed;
} PhysicsObj;

class Physics{
public:
    void apply_gravity(PhysicsObj* pObj);
    void static move(PhysicsObj* pObj, Vector2 dir, float speed);
};