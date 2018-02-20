//
//  Renderer.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 02/14/18.
//  Copyright © 2018 Anish Bhobe. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include "Sprite.hpp"

namespace inferno {
namespace graphics {
/// @class Renderer
/// @brief Holds the sprite to render, sorts and renders at the call.
/// @details This class is used to make spritebatches such that the performance
/// of the game increases.
/// Use this for the rendering
/// @author Anish Bhobe
/// @date 02.14.2018
class Renderer {
public:
	/// Simple constructor. Initializes the renderer.
	/// @param renderer SDL_Renderer of the current render target
	Renderer(SDL_Renderer *renderer) :
			renderer(renderer) {}
	/// Draws on the screen using sprite and position
	/// @param sprite Sprite to be draw
	/// @param position Vector2 position at which to draw the sprite
	void draw(Sprite sprite, Vector2 position);

	/// Draws on the screen using sprite and destination Quad
	/// @param sprite Sprite to be draw
	/// @param dest_region Quad region of screen at which to draw the sprite
	void draw(Sprite sprite, Quad dest_region);

	/// Draws on the screen using sprite and position
	/// @param sprite Sprite to be draw
	/// @param position Vector2 position at which to draw the sprite
	/// @param rotation The rotation of the sprite around center
	/// @param scale The scaling of the sprite in the two dimensions.
	void draw(Sprite sprite, Vector2 position, float rotation, Vector2 scale);

	/// Actually renders on the screen (TODO)
	void render();

private:
	SDL_Renderer *renderer;
    vector<DrawCall> draw_calls;
    struct DrawCall{
        Sprite sprite;
        Vector2 position;
        float rotation;
        Vector2 scale;

        DrawCall(Sprite sprite, Vector2 position, float rotation, Vector2 scale){
            this->sprite = sprite;
            this->position = position;
            this->rotation = rotation;
            this->scale = scale;
        }
    }
};
} // namespace graphics
} // namespace inferno

#endif /* Renderer_hpp */
