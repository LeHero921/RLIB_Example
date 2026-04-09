#pragma once
#include "QuantuumFrame/QuantuumFrame.h"

class Player {
public:
    Player();
    ~Player();

    Entity PlayerEntity;

    void MovePlayer(Entity* player);
};