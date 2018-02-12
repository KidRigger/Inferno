//
//  TextureManager.cpp
//  InfernoEngine
//
//  Created by Ravishankar Joshi on 1/17/18.
//  Copyright © 2018 Anish Bhobe. All rights reserved.
//

#include "TextureManager.hpp"
#include "Texture.hpp"
#include <memory>

void inferno::graphics::TextureManager::Load(std::string texture_filename,
                                        std::string texture_name) {

    TextureHandle handle = std::make_shared<Texture>(renderTarget,texture_filename, texture_name);

    this->textures.insert({handle->GetHash(), handle});
}

void inferno::graphics::TextureManager::LoadAll(
    std::vector<std::string> texture_filenames,
    std::vector<std::string> texture_names) {

    textures.clear();

    if(texture_filenames.size() != texture_names.size()) {
        throw std::runtime_error("Number of filenames and \
		number of names of textures must be same.");
    }

    auto n = texture_filenames.size();
    for(size_t i = 0; i<n; i++) {
        this->Load(texture_filenames.at(i), texture_names.at(i));
    }
}

void inferno::graphics::TextureManager::Unload(std::string texture_name) {

    this->textures.erase(std::hash<std::string>{}(texture_name));
}

void inferno::graphics::TextureManager::UnloadAll() {
    this->textures.clear();
}

inferno::graphics::TextureHandle
inferno::graphics::TextureManager::Get(std::string texture_name) const {
    auto iterator = this->textures.find(std::hash<std::string>{}(texture_name));
    if(iterator == this->textures.end()) {
        throw std::runtime_error("No such texture with name "+ texture_name);
    }
    return iterator->second;
}

inferno::graphics::TextureHandle
inferno::graphics::TextureManager::operator[](std::string texture_name) const {
    return this->Get(texture_name);
}
