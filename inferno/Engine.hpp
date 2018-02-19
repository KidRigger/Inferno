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
class Engine {
private:
	time_t previousTime;
	bool running;

public:
	Engine();
	template <class Game>
	void run();
	static void rest(float time_in_seconds);
	bool is_engine_ready();
	~Engine();
};
} // namespace inferno

#endif /* Engine_hpp */
