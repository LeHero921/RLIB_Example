#include "physics.h"
#include "base.h"

void Physics::apply_gravity(PhysicsObj* pObj)
{
    pObj->velocity.y += 10.0;
    if (pObj->velocity.y >= 200.0)
    {
        pObj->velocity.y = 200.0;
    }
};

void Physics::apply_velocity(entityData* _data)
{

};

void Physics::move(PhysicsObj* pObj)
{
    float speed = pObj->speed;
    pObj->velocity.x = pObj->direction.x * speed * GetFrameTime();
    pObj->velocity.y = pObj->direction.y * speed * GetFrameTime();
};