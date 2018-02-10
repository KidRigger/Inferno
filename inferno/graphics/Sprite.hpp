//
//  Sprite.hpp
//  InfernoEngine2
//
//  Created by Anish Bhobe on 7/19/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include "Texture.hpp"

namespace inferno {
    namespace graphics {
        
        // class Sprite
        // Just holds together a texture handle and the region mapping
        // To take one specific sprite out of a spritemap.
        class Sprite {
            
        public:
            // Simple ctor
            Sprite(TextureHandle texture_handle, Quad region):
            txr(texture_handle),region(region) {}
            
            // Full texture as sprite
            Sprite(TextureHandle texture_handle):
            txr(texture_handle), region(texture_handle->GetRectangle()) {}
            // Default ctor
            Sprite() = default;
            
            // Gets TextureHandle
            TextureHandle GetTexture() { return txr; }
            
            // Gets the region
            Quad GetRegion() { return region; }
            
        private:
            TextureHandle txr;
            Quad region;
        };
    }
}

#endif // Sprite_hpp //
