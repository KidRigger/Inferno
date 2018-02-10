//
//  Engine.hpp
//  Shades
//
//  Created by Anish Bhobe on 11/9/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#ifndef Engine_hpp
#define Engine_hpp

#include <allegro5/allegro.h>
#include <ctime>

namespace inferno {
    class Engine
    {
    private:
        time_t previousTime;
        bool run;
    public:
        Engine();
        template <class Game> void Run();
        static void Rest(float timeInSeconds);
        bool IsEngineReady();
    };
}

#endif /* Engine_hpp */
