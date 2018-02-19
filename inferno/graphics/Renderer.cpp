//
//  Renderer.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 02/14/18.
//  Copyright © 2018 Anish Bhobe. All rights reserved.
//

#include "Renderer.hpp"

using inferno::graphics::Renderer;

void Renderer::draw(Sprite sprite, Vector2 position) {
	Quad temp_quad(position, sprite.get_region().get_diagonal());
	SDL_RenderCopy(renderer, sprite.get_texture()->get_texture(), temp_quad.get_rect(), sprite.get_region().get_rect());
}

void Renderer::draw(Sprite sprite, Quad dest_region) {
	SDL_RenderCopy(renderer, sprite.get_texture()->get_texture(), dest_region.get_rect(), sprite.get_region().get_rect());
}

void Renderer::draw(Sprite sprite, Vector2 position, float rotation, Vector2 scale) {
	Quad temp_quad(position, sprite.get_region().get_diagonal());
	SDL_RenderCopy(renderer, sprite.get_texture()->get_texture(), temp_quad.get_rect(), sprite.get_region().get_rect());
}
