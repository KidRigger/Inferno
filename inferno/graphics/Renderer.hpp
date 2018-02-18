//
//  Renderer.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 02/14/18.
//  Copyright © 2018 Anish Bhobe. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

namespace inferno {
namespace graphics {
class Renderer {
public:
	Renderer(SDL_Renderer *renderer) :
			renderer(renderer) {}
	void Draw(Sprite sprite, Vector2 position);
	void Draw(Sprite sprite, Quad dest_region);
	void Draw(Sprite sprite, Vector2 position, float rotation, Vector2 scale);
	void Render();

private:
	SDL_Renderer *renderer;
}
} // namespace graphics
} // namespace inferno

#endif /* Renderer_hpp */
