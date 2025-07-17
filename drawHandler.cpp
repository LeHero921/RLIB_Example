#include "drawHandler.h"

void DrawHandler::RenderEntity(const entityData& data)
{
    DrawTexturePro(
        data.renderer.sprite.texture,
        data.renderer.sprite.source_rect,
        data.renderer.sprite.dest_rect,
        data.transform.position,
        data.transform.rotation,
        data.renderer.tint
    );
};