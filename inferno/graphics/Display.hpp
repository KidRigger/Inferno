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

namespace inferno {
    namespace graphics {
        // Display class to handle both allegro and the display screen
        class Display {
        public:
            // Constructor of the display of width and height and init allegro if it wasn't
            Display(int width, int height):width(width),height(height) {
                // TODO: Move to Engine ctor
                if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
                    std::cerr << "SDL could not initialize. " << SDL_GetError() << std::endl;
                    return false;
                }

                window = SDL_CreateWindow(
                                        "SDL Tutorial",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        width, height,
                                        SDL_WINDOW_SHOWN
                                    );

                if (window == nullptr) {
                    std::cerr << "Window could not be opened." << SDL_GetError() << std::endl;
                    return false;
                }

                screenSurface = SDL_GetWindowSurface(window);
                return true;
            }

            // Resizing the display using allegros function
            void Resize(int width, int height) {
                // TODO: SDL_Display resize
            }

            // Update the display
            void Refresh() {
                SDL_UpdateWindowSurface(window);
            }

            // Clear the display
            void Clear() {
                SDL_FillRect(screenSurface,NULL,SDL_MapRGB());
            }

            // Set background color
            void SetBackgroundColor() {
                // TODO: Color
            }

            // Destructor destroys display
            ~Display() {
                // TODO: dtor
            }
        private:
            SDL_Window* window = nullptr;
            SDL_Surface* screenSurface = nullptr;
            int width, height;
            ALLEGRO_COLOR background_color;
        };
    }
}

#endif /* Display_hpp */
