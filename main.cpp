#include "inferno/graphics/Display.hpp"
#include "inferno/graphics/Texture.hpp"
#include "inferno/graphics/TextureManager.hpp"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *window = nullptr;
SDL_Surface *screenSurface = nullptr;

bool init();
void close();
void refresh();

int main(int argc, char *argv[]) {

	inferno::graphics::Display disp(640, 480);

	inferno::graphics::TextureManager tm(disp.get_renderer());
	tm.load("../character_hurt.png", "charhurt");
	inferno::graphics::TextureHandle h1 = tm["charhurt"];

	SDL_Event ev;
	bool running = true;
	while (running) {
		while (SDL_PollEvent(&ev) != 0) {
			if (ev.type == SDL_QUIT) {
				running = false;
			}
		}
		disp.clear();
		disp.refresh();
		SDL_Delay(200);
		SDL_RenderCopy(disp.get_renderer(), h1->get_texture(), NULL, h1->get_quad().get_rect());
		disp.refresh();
		SDL_Delay(200);
	}

	return 0;
}
