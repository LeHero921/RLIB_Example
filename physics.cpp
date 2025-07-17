#include "physics.h"
#include "base.h"
#include "entity.h"

void Physics::apply_gravity(PhysicsObj* pObj)
{
    pObj->velocity.y += 10.0;
    if (pObj->velocity.y >= 200.0)
    {
        pObj->velocity.y = 200.0;
    }
};

void Physics::move(PhysicsObj* pObj, Vector2 dir, float speed)
{
    pObj->velocity.x = dir.x * speed * GetFrameTime();
};