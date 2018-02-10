//
//  SpriteBatch.cpp
//  Shades
//
//  Created by Anish Bhobe on 1/10/18.
//  Copyright © 2018 Anish Bhobe. All rights reserved.
//

#include "SpriteBatch.hpp"
#include <allegro5/allegro.h>

using inferno::graphics::SpriteBatch;
using inferno::graphics::Quad;
using inferno::graphics::TextureHandle;
using inferno::graphics::Color;
using inferno::graphics::Sprite;

void SpriteBatch::DrawCall(TextureHandle txr, Quad src, Vector2 position,
                       float rotation, Vector2 scale, Color tint,
                       DrawFlags flags) {
    al_draw_tinted_scaled_rotated_bitmap_region(txr->GetBitmap(),
                                                src.x(), src.y(),
                                                src.w(), src.h(),
                                                tint.GetColor(),
                                                src.w()/2, src.h()/2,
                                                position.x(), position.y(),
                                                scale.x(), scale.y(),
                                                rotation,
                                                static_cast<int>(flags));
}

void SpriteBatch::Draw(Sprite sprite, Vector2 position, float rotation,
                       Vector2 scale, Color tint, DrawFlags flags) {
    sub_queue.push_back(Submission(sprite.GetTexture(),sprite.GetRegion(),
                        position,rotation,scale,tint,flags));
}

void SpriteBatch::End() {
    std::sort(sub_queue.begin(),sub_queue.end(), Submission::Comparator{});
    al_hold_bitmap_drawing(true);
    for (Submission& sub: sub_queue) {
        DrawCall(sub.texture_handle, sub.source_quad, sub.position,
                 sub.rotation, sub.scale, sub.tint, sub.flags);
    }
    al_hold_bitmap_drawing(false);
    sub_queue.clear();
}

inferno::graphics::Submission::Submission(TextureHandle txr, Quad src,
                                          Vector2 position, float rotation,
                                          Vector2 scale, Color tint,
                                          DrawFlags flags):
texture_handle(txr),source_quad(src),position(position),rotation(rotation),
scale(scale),tint(tint),flags(flags) { };