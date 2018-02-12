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
    namespace graphics {

        class TextureManager {
        public:
            // default ctor
            TextureManager(SDL_Renderer* renderTarget) : renderTarget(renderTarget) {}

            // Copy semantics disabled
            TextureManager(const TextureManager& texture_manager) = default;
            TextureManager& operator=(const TextureManager& texture_manger) = default;

            // Move semantics enabled
            TextureManager(TextureManager&& texture_manager):
            textures(texture_manager.textures){};

            TextureManager& operator=(TextureManager&& texture_manager){
				this->textures= std::move(texture_manager.textures);
                return *this;
            }

            void Load(std::string texture_filename, std::string texture_name);

            void LoadAll(std::vector<std::string> texture_filenames,
                         std::vector<std::string> texture_names);

            void Unload(std::string texture_name);
            void UnloadAll();

            inferno::graphics::TextureHandle Get(std::string texture_name) const;

            inferno::graphics::TextureHandle operator[](std::string texture_name) const;

            // Dtor
            ~TextureManager() {textures.clear();}
        private:
            std::map<size_t, TextureHandle> textures;
            SDL_Renderer* renderTarget;
        };
    }
}

#endif /* TextureManager_hpp */
