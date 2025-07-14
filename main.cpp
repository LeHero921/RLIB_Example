#include <raylib.h>

typedef struct Sprite
{
    Texture2D texture;
    Rectangle dest_rect;
} Sprite;


int main()
{
    #pragma region INIT
    InitWindow(100, 100, "RayLib Example");

    Texture2D playerTexture = LoadTexture("assets/sword.png");
    Sprite player = (Sprite){
        .texture = playerTexture,
        .dest_rect = (Rectangle) {
            .x = 10,
            .y = 100,
            .width = 100,
            .height = 100,
        }
    };

    while (!WindowShouldClose())
    {
        #pragma region RUN
        BeginDrawing();

        ClearBackground(SKYBLUE);
        // DrawTexture(playerTexture, 0,0, RAYWHITE);
        DrawTexturePro(
            playerTexture, 
            (Rectangle){ 0, 0, 32, 32 }, 
            (Rectangle){ 10, 100, 100, 100 }, 
            (Vector2){ 0, 0 }, 
            0.0f, 
            RAYWHITE
        );
        // DrawTexturePro(player.texture, {0, 0, 16, 16}, player.dest_rect, {0,0}, 0.0, RAYWHITE);

        EndDrawing();
    }
    #pragma region EXIT
    CloseWindow();

    UnloadTexture(playerTexture);

    return 0;
}