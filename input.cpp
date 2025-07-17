#include <raylib.h>
#include "input.h"

Vector2 Input::GetDirectionalInput() {
    Vector2 _dir;
    _dir.x = IsKeyDown(KEY_D);
    _dir.y = IsKeyDown(KEY_W);
    return _dir;
};