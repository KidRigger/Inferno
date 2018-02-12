//
//  Texture.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 7/17/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Rectangle.hpp"
#include <memory>

namespace inferno {
    namespace graphics {
        class Texture {
        public:
            // ctor
            // loads texture texture_name from file texture_filename
            Texture(SDL_Renderer* renderer, std::string texture_filename, std::string texture_name);

            // default ctor
            Texture() = default;

            // Copy semantics disabled
            Texture(const Texture& texture) = delete;
            Texture& operator=(const Texture& texture) = delete;

            // Move semantics enabled
            Texture(Texture&& texture):
            texture_id(texture.texture_id),
            size(texture.size) {
                texture_bitmap = texture.texture_bitmap;
                texture.texture_bitmap = nullptr;
            }
            Texture& operator=(Texture&& texture) {
                texture_id = texture.texture_id;
                size = texture.size;
                texture_bitmap = texture.texture_bitmap;
                texture.texture_bitmap = nullptr;
                return *this;
            }

            // Get the region of the entire texture
            Quad GetQuad() const;

            // Get the hash of the texture_id string
            size_t GetHash() const;

            // Get a raw pointer to the bitmap.
            SDL_Texture* GetTexture() const { return texture_bitmap; };

            // Dtor
            ~Texture();
        private:
            std::string texture_id;
            size_t hash_id;
            SDL_Texture *texture_bitmap = nullptr;
            Quad size;
        };

        typedef std::shared_ptr<Texture> TextureHandle;
    }
}

#endif /* Texture_hpp */
