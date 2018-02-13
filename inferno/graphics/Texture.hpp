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
#include "Quad.hpp"
#include <memory>

namespace inferno {
    namespace graphics {
        /// @class Texture
        /// @brief RAII Class for SDL_Textures.
        /// Texture is used to automatically deallocate and ease of transfer
        /// in files without the allocation responsibilities.
        /// Only a container. Use Sprite for drawing.
        /// @see Sprite
        class Texture {
        public:
            /// @brief Constructor for the Texture class.
            /// Texture is cosntructed to a texture in a given file using the
            /// SDL_Renderer from the current display window.
            /// @param renderer SDL_Renderer from the rendering target
            /// @param texture_filename Path to the file containing the Texture asset
            /// @param texture_name Unique ID to refer to this texture and hashing the texture
            Texture(SDL_Renderer* renderer, std::string texture_filename, std::string texture_name);

            /// @brief Default constructor.
            Texture() = default;

            /// @brief Copy Constructor is deleted.
            Texture(const Texture& texture) = delete;

            /// @brief Copy Assignment is deleted.
            Texture& operator=(const Texture& texture) = delete;

            /// @brief Move Constructor
            /// Moves the given Texture into self and frees the other texture.
            /// @param texture Other texture that is to be moved.
            Texture(Texture&& texture):
            texture_id(texture.texture_id),
            size(texture.size) {
                texture_bitmap = texture.texture_bitmap;
                texture.texture_bitmap = nullptr;
            }

            /// @brief Move assignment.
            /// Assigns value to the new texture and deletes the older textures
            /// to prevent existance of multiple copies responsible for the same resources.
            /// @param texture The texture that is to be moved into this.
            Texture& operator=(Texture&& texture) {
                texture_id = std::move(texture.texture_id);
                size = std::move(texture.size);
                texture_bitmap = texture.texture_bitmap;
                texture.texture_bitmap = nullptr;
                return *this;
            }

            /// @brief Get the Quad that encompases the region of the entire texture.
            /// @returns Quad containing dimensions of the texture.
            Quad GetQuad() const;

            /// @brief Get the hash of the texture_id string
            /// @returns size_t containing the hash of texture_id.
            size_t GetHash() const;

            /// @brief Get a raw pointer to the bitmap.
            /// Facilitates the getting of the raw pointer from the class for
            /// interfacing with the rest of SDL functions. \n
            /// Do not delete the raw pointer. The responsibility lies with This
            /// class only.
            /// @returns SDL_Texture pointer to the stored texture.
            SDL_Texture* GetTexture() const { return texture_bitmap; };

            // Dtor
            ~Texture();
        private:
            std::string texture_id;
            size_t hash_id;
            SDL_Texture *texture_bitmap = nullptr;
            Quad size;
        };

        /// @typedef std::shared_ptr<Texture> TextureHandle;
        /// TextureHandle just rename of shared_ptr<Texture> for convenience.
        typedef std::shared_ptr<Texture> TextureHandle;
    }
}

#endif /* Texture_hpp */
