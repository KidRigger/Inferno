//
//  Engine.cpp
//  Shades
//
//  Created by Anish Bhobe on 11/9/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#include "Engine.hpp"
#include <iostream>


inferno::Engine::Engine():run(true) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL could not initialize. " << SDL_GetError() << std::endl;
        throw std::runtime_error("Failed to start");
    }
}

void inferno::Engine::Rest(float timeInSeconds) {
    // TODO: Sleep
}

inferno::Engine::~Engine() {
    SDL_Quit();
}

template <class Level>
void inferno::Engine::Run() {
    Level lvl;
    lvl.Start();
    lvl.LoadContent();
    while(run)
    {
        lvl.Update();
    }
    lvl.UnloadContent();
}
