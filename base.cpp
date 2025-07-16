#include "base.h"

bool glContext;

bool Base::IsValidTexture(const Texture2D& texture) {
    return texture.id != 0; // 0 = ungültige Texture in raylib
};

bool Base::IsValidRect(const Rectangle& rect) {
    return rect.width != 0 && rect.height != 0;
};

bool Base::IsValidSprite(const Sprite& sprite) {
    return IsValidTexture(sprite.texture) &&
           IsValidRect(sprite.dest_rect) &&
           IsValidRect(sprite.source_rect);
};

bool Base::IsValidRenderStructure(const RenderStructure& rs) {
    return IsValidSprite(rs.sprite);
};

bool Base::valid_glCtx()
{
    return true;
};