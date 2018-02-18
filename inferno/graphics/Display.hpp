//
//  Display.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 7/21/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#ifndef Display_hpp
#define Display_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>

namespace inferno {
namespace graphics {
/// @class Display
/// @brief RAII class to handle SDL_Display screen.
/// @details Constructs and initializes a SDL display and renderer for use and owns the both.
/// Also initializes SDL as of now.
/// @author Anish Bhobe
/// @date 07.21.2017
class Display {
public:
	/// Constructs a display of width and height and initializes SDL (temp)
	/// @param width The required width of the display
	/// @param height The required height of the display
	Display(int width, int height) :
			width(width),
			height(height) {
		// TODO: Move to Engine ctor
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			std::cerr << "SDL could not initialize. " << SDL_GetError() << std::endl;
			throw std::runtime_error("Failed to start");
		}

		if (width == 0 || height == 0) {
			window = SDL_CreateWindow(
					"SDL Tutorial",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					640, 480,
					SDL_WINDOW_HIDDEN);
		}
		// Create SDL window
		window = SDL_CreateWindow(
				"SDL Tutorial",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				width, height,
				SDL_WINDOW_SHOWN);

		if (window == nullptr) {
			std::cerr << "Window could not be opened." << SDL_GetError() << std::endl;
			throw std::runtime_error("Failed to create display");
		}

		// Get the renderer for the window.
		renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		if (renderTarget == nullptr) {
			std::cerr << "Renderer could not be created." << SDL_GetError() << std::endl;
			throw std::runtime_error("Renderer creation failed.");
		}
	}

	/// Resize the display to the given width and height
	/// @param width The required width of display.
	/// @param height The required height of display.
	void Resize(int width, int height) {
		// TODO: SDL_Display resize
	}

	/// Updates the display
	/// Refreshes the display by rendering everything in the buffer on the screen.
	void Refresh() {
		SDL_RenderPresent(renderTarget);
	}

	/// Clear the display
	/// Clears the display to blank.
	void Clear() {
		SDL_RenderClear(renderTarget);
	}

	/// Set background color
	/// Sets a background color
	void SetBackgroundColor() {
		// TODO: Color
	}

	/// Destructor destroys display
	~Display() {
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	/// Gets a pointer to the SDL_Window
	/// @returns SDL_Window pointer to the SDL window.
	SDL_Window *GetWindow() {
		return window;
	}

	/// Gets a pointer to the SDL_Renderer
	/// @returns SDL_Renderer pointer to the renderer used by the display.
	SDL_Renderer *GetRenderer() {
		return renderTarget;
	}

private:
	SDL_Window *window = nullptr;
	SDL_Renderer *renderTarget = nullptr;
	int width, height;
};
} // namespace graphics
} // namespace inferno

#endif /* Display_hpp */
