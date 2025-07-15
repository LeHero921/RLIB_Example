// #include <raylib.h>
#include "base.h"
#include "player.h"
#include "debug.h"

int main()
{
    float screenX = 800;
    float screenY = 600;
    #pragma region INIT
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(screenX, screenY, "RayLib Example");
    bool glContext = true;

    Texture2D playerTexture = LoadTexture("assets/LuisMiniGame_Character.png");
    Player player;
    Physics physics;

    player.PlayerEntity.entitySprite.texture = playerTexture;
    player.PlayerEntity.entitySprite.dest_rect = {screenX - screenX/2 - playerTexture.width + playerTexture.width/2, screenY-screenY/2 - playerTexture.height + playerTexture.height/2 ,50,50};

    while (!WindowShouldClose())
    {
        player.MovePlayer(&player.PlayerEntity);
        physics.apply_gravity(&player.PlayerEntity.physicsObj);

        #pragma region RUN
        BeginDrawing();

        ClearBackground(SKYBLUE);
        
        DrawTexturePro(player.PlayerEntity.entitySprite.texture, {0,0,16,16}, player.PlayerEntity.entitySprite.dest_rect, {0,0},0, RAYWHITE);

        EndDrawing();
    }
    #pragma region EXIT
    CloseWindow();

    UnloadTexture(playerTexture);

    return 0;
}