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
    if(!al_is_system_installed()) {
        if (!al_init()) {
            throw "Allegro could not be initialized";
        }
        else {
            std::cerr << "Allegro Initialized" << std::endl;
        }
    }
    else {
        std::cerr << "Warning: Second engine created. Allegro already initialized" << std::endl;
    }
}

void inferno::Engine::Rest(float timeInSeconds) {
    std::cerr << "Rest for " << timeInSeconds << " seconds" << std::endl;
    al_rest(timeInSeconds);
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


