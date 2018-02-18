//
//  Texture.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 7/17/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#include "Texture.hpp"
#include <iostream>

inferno::graphics::Texture::Texture(SDL_Renderer *renderer,
		std::string texture_filename,
		std::string texture_name) :
		texture_id(texture_name),
		hash_id(std::hash<std::string>{}(texture_name)) {

	// Loads bitmap using SDL_Image
	SDL_Surface *tempSurface = IMG_Load(texture_filename.c_str());

	if (tempSurface == nullptr) {
		throw std::runtime_error("Texture (" + texture_id + ") could not be loaded to RAM");
	}

	texture_bitmap = SDL_CreateTextureFromSurface(renderer, tempSurface);

	// Checks if the bitmap was loaded
	if (texture_bitmap == nullptr) {
		throw std::runtime_error("Texture (" + texture_id + ") could not be loaded to GPU");
	}

	SDL_FreeSurface(tempSurface);
	tempSurface = nullptr;

	// Gets the size of the loaded texture
	int w, h;
	SDL_QueryTexture(texture_bitmap, NULL, NULL, &w, &h);
	size.x() = 0;
	size.y() = 0;
	size.w() = w;
	size.h() = h;
}

inferno::graphics::Quad inferno::graphics::Texture::GetQuad() const {
	return size;
}

size_t inferno::graphics::Texture::GetHash() const {
	return hash_id;
}

inferno::graphics::Texture::~Texture() {
	// Destroy the bitmap and do away with the dangling pointer
	SDL_DestroyTexture(texture_bitmap);
	texture_bitmap = nullptr;
}
