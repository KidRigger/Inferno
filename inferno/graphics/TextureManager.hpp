//
//  TextureManager.hpp
//  InfernoEngine
//
//  Created by Ravishankar Joshi on 1/17/18.
//  Copyright © 2018 Anish Bhobe. All rights reserved.
//

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include "Texture.hpp"
#include <string>
#include <memory>
#include <stdexcept>
#include <vector>
#include <map>

namespace inferno {
    /// @namespace graphics
    /// Graphics namespace contains classes used for rendering and image loading.
    namespace graphics {
        /// @class TextureManager
        /// @brief Manager class that loads and stores Textures for ease of access.
        /// Stores the textures into a map which allows easy access using the string
        /// ids using hashes. And stores the filename in a map to prevent reloading existing
        /// textures.
        class TextureManager {
        public:
            /// Minimal constructor.
            /// Takes the SDL_Renderer of the render target (display) at construction
            /// to use for constructing the textures.
            /// @param renderTarget SDL_Renderer from the display window.
            TextureManager(SDL_Renderer* renderTarget) : renderTarget(renderTarget) {}

            /// Copy construction disabled.
            /// Only need one TextureManager at a time.
            /// So disabling copy to ensure copies of the manager don't exist.
            TextureManager(const TextureManager& texture_manager) = delete;

            /// Copy assignment disabled.
            /// Only need one TextureManager at a time.
            /// So disabling copy to ensure copies of the manager don't exist.
            TextureManager& operator=(const TextureManager& texture_manger) = delete;

            /// Move constructor.
            /// Moves the existing texture_manager into the new texture_manager and
            /// destroys the original.
            /// @param texture_manager the texture manager to be moved in.
            TextureManager(TextureManager&& texture_manager):
            textures(texture_manager.textures){};

            /// Move assignment
            /// Moves the existing texture_manager into this texture_manager and
            /// destroys the original.
            /// @param texture_manager the texture manager to be moved in.
            TextureManager& operator=(TextureManager&& texture_manager){
				this->textures= std::move(texture_manager.textures);
                return *this;
            }

            /// Loads a texture.
            /// Loads a texture from the given \a texture_filename and allows reaccess using the \a texture_name
            /// @param texture_filename The path to file containing the texture.
            /// @param texture_name The unique identifier for the texture to recall the loaded texture.
            void Load(std::string texture_filename, std::string texture_name);

            /// Loads multiple textures together.
            /// Loads the Textures from the filesnames and saves with the corresponding
            /// IDs.
            /// @param texture_filenames The vector containing the paths for each texture.
            /// @param texture_names The IDs by which to store the textures.
            void LoadAll(std::vector<std::string> texture_filenames,
                         std::vector<std::string> texture_names);

            /// Unloads the texture.
            /// Unloads the texture specified by the given texture_name on call.
            /// @param texture_name String containing the ID of the texture to unload.
            void Unload(std::string texture_name);

            /// Unloads all textures.
            /// Unloads all the textures so no texture remains. \n
            /// Simply clears out the map.
            void UnloadAll();

            /// Gets the number of textures stored.
            /// @returns Number of textures stored in the class.
            size_t size() { return textures.size(); }

            /// Gets the required texture.
            /// Looks up in for the TextureHandle corresponding to the texture_name
            /// stored in the file.
            /// @returns TextureHandle referencing the called for texture.
            inferno::graphics::TextureHandle Get(std::string texture_name) const;

            /// Gets the required texture.
            /// Looks up in for the TextureHandle corresponding to the texture_name
            /// stored in the file.
            /// @returns TextureHandle referencing the called for texture.
            inferno::graphics::TextureHandle operator[](std::string texture_name) const;

            /// Destructor.
            ~TextureManager() {textures.clear();}
        private:
            std::map<size_t, TextureHandle> textures;
            SDL_Renderer* renderTarget;
        };
    }
}

#endif /* TextureManager_hpp */
