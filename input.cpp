#include "input.h"
#include <raylib.h>

Vector2 Input::GetDirectionalInput() {
    Vector2 _dir;

    if (IsKeyDown(KEY_A)) { _dir.x = -1; }
    else { _dir.x = 0; }

    if (IsKeyDown(KEY_S)) { _dir.y = -1; }
    else { _dir.y = 0; }

    if (IsKeyDown(KEY_D)) { _dir.x = 1; }

    if (IsKeyDown(KEY_W)) { _dir.y = 1; }

    return _dir;
};