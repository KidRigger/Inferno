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

inferno::graphics::TextureHandle inferno::graphics::TextureManager::load(std::string texture_filename,
		std::string texture_name) {

	TextureHandle handle = std::make_shared<Texture>(renderTarget, texture_filename, texture_name);

	return this->textures.insert({ handle->get_hash(), handle }).first->second;
}

void inferno::graphics::TextureManager::load_all(
		std::vector<std::string> texture_filenames,
		std::vector<std::string> texture_names) {

	textures.clear();

	if (texture_filenames.size() != texture_names.size()) {
		throw std::runtime_error("Number of filenames and \
		      number of names of textures must be same.");
	}

	auto n = texture_filenames.size();
	for (size_t i = 0; i != n; ++i) {
		this->load(texture_filenames[i], texture_names[i]);
	}
}

void inferno::graphics::TextureManager::unload(std::string texture_name) {

	this->textures.erase(std::hash<std::string>{}(texture_name));
}

void inferno::graphics::TextureManager::unload_all() {
	this->textures.clear();
}

inferno::graphics::TextureHandle
inferno::graphics::TextureManager::get(std::string texture_name) const {
	auto iterator = this->textures.find(std::hash<std::string>{}(texture_name));
	if (iterator == this->textures.end()) {
		throw std::runtime_error("No such texture with name " + texture_name);
	}
	return iterator->second;
}

inferno::graphics::TextureHandle
		inferno::graphics::TextureManager::operator[](std::string texture_name) const {
	return this->get(texture_name);
}
