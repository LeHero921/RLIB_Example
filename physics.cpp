#include "base.h"
#include "physics.h"
#include "entity.h"

void Physics::apply_gravity(PhysicsObj* pObj)
{
    pObj->velocity.y += 10.0;
    if (pObj->velocity.y >= 200.0)
    {
        pObj->velocity.y = 200.0;
    }
};