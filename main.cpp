#include "base.h"
#include "player.h"
#include "debug.h"
#include "drawHandler.h"

int main()
{
    float screenX = 800;
    float screenY = 600;
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(screenX, screenY, "RayLib Example");

    //TODO: implement active glcontext validation

    DrawHandler draw;
    Texture2D playerTexture = LoadTexture("assets/LuisMiniGame_Character.png");
    // Player player;
    Physics physics;
    
    Texture2D eTex = LoadTexture("assets/sword.png");
    Sprite eSprite = {
        eTex,
        {100,100,16,16},
        {0,0,16,16}
    };
    RenderStructure eRender = {eSprite, WHITE};
    qTransform eTrans = { {100,100}, 0.0f};
    PhysicsObj ePO = { {0,0}, 1.0f };
    Entity e(eTrans, eRender, ePO);

    // player.PlayerEntity.entitySprite.texture = playerTexture;
    // player.PlayerEntity.entitySprite.dest_rect = {screenX - screenX/2 - playerTexture.width + playerTexture.width/2, screenY-screenY/2 - playerTexture.height + playerTexture.height/2 ,50,50};

    while (!WindowShouldClose())
    {
        // player.MovePlayer(&player.PlayerEntity);
        // physics.apply_gravity(&player.PlayerEntity.physicsObj);

        #pragma region RUN
        BeginDrawing();
        ClearBackground(SKYBLUE);

        draw.RenderEntity(e._data); //TODO: Implement glContext validation securety!!!
        
        // DrawTexturePro(player.PlayerEntity.entitySprite.texture, {0,0,16,16}, player.PlayerEntity.entitySprite.dest_rect, {0,0},0, RAYWHITE);

        EndDrawing();
    }
    #pragma region EXIT
    CloseWindow();

    UnloadTexture(playerTexture);
    UnloadTexture(eTex);

    return 0;
}