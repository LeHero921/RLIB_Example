#include "base.h"
#include "player.h"
#include "debug.h"
#include "drawHandler.h"
#include "resourceLoader.h"
#include "input.h"

std::string ToString(const Vector2& v) {
    return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ")";
}

int main()
{
    float screenX = 800;
    float screenY = 600;
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(screenX, screenY, "RayLib Example");

    //TODO: implement active glcontext validation

    DrawHandler draw;
    Physics physics;
    // Input input;
    

    entityConfig playerConf = {
        "assets/monster.png",
        {screenX/2 -50, screenY/2 -50},
        {100,100},
        WHITE,
        0,
        {0,0},
        1,
        100,
    };
    Entity player = Entity::create_entity(playerConf);

    while (!WindowShouldClose())
    {
        player._data.physicsObj.direction = Input::GetDirectionalInput();
        Debug::log(ToString(player._data.physicsObj.direction));
        physics.move(&player._data.physicsObj);
        physics.apply_velocity(&player._data);

        #pragma region RUN
        BeginDrawing();
        ClearBackground(SKYBLUE);

        //TODO: Implement glContext validation securety!!!
        draw.RenderEntity(player._data);

        EndDrawing();
    }
    #pragma region EXIT
    CloseWindow();

    ResourceLoader::unloadAll();

    return 0;
}