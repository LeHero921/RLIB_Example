#pragma once
#include "base.h"
#include "entity.h"

class Player {
public:
    Player();
    ~Player();

    Entity PlayerEntity;

    void MovePlayer(Entity* player);
};