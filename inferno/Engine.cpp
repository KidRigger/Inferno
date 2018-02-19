//
//  Engine.cpp
//  Shades
//
//  Created by Anish Bhobe on 11/9/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#include "Engine.hpp"
#include <iostream>

inferno::Engine::Engine() :
		running(true) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "SDL could not initialize. " << SDL_GetError() << std::endl;
		throw std::runtime_error("Failed to start");
	}
}

void inferno::Engine::rest(float time_in_seconds) {
	// TODO: Sleep
}

inferno::Engine::~Engine() {
	SDL_Quit();
}

template <class Level>
void inferno::Engine::run(Level lvl) {
	lvl.start();
	lvl.load_content();
	while (running) {
		lvl.update();
	}
	lvl.unload_content();
}
