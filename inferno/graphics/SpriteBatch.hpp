//
//  SpriteBatch.hpp
//  Shades
//
//  Created by Anish Bhobe on 1/10/18.
//  Copyright © 2018 Anish Bhobe. All rights reserved.
//

#ifndef SpriteBatch_hpp
#define SpriteBatch_hpp

#include "Color.hpp"
#include "Sprite.hpp"
#include <allegro5/allegro.h>
#include <vector>

namespace inferno {
    namespace graphics {
        
        struct Submission {
            TextureHandle texture_handle;
            Quad source_quad;
            Vector2 position;
            float rotation;
            Vector2 scale;
            Color tint;
            DrawFlags flags;
            
            Submission(TextureHandle txr, Quad src, Vector2 position,
                       float rotation = 0, Vector2 scale = Vector2(1,1),
                       Color tint = Color(255,255,255),
                       DrawFlags flags = DrawFlags::None);
            
            class Comparator {
            public:
                int operator () (Submission left, Submission right) {
                    return left.texture_handle->GetHash() < right.texture_handle->GetHash();
                }
            };
        };
        
        //
        // SpriteBatch
        // Not yet implemented to really batch
        // Simply draws
        //
        class SpriteBatch{
        public:
            void Draw(Sprite sprite, Vector2 position,
                      float rotation = 0,
                      Vector2 scale = Vector2(1,1),
                      Color tint = Color(255,255,255),
                      DrawFlags = DrawFlags::None);
            void End();
        private:
            std::vector<Submission> sub_queue;
            
            void DrawCall(TextureHandle txr, Quad src, Vector2 position,
                          float rotation = 0, Vector2 scale = Vector2(1,1),
                          Color tint = Color(255,255,255),
                          DrawFlags flags = DrawFlags::None);
        };
    }
}


#endif /* SpriteBatch_hpp */
