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
                    throw std::runtime_error("Failed to start");
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
                    throw std::runtime_error("Failed to create display");
                }

                //screenSurface = SDL_GetWindowSurface(window);

                renderTarget = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

                if (renderTarget == nullptr) {
                    std::cerr << "Renderer could not be created." << SDL_GetError() << std::endl;
                    throw std::runtime_error("Renderer creation failed.");
                }
            }

            // Resizing the display using allegros function
            void Resize(int width, int height) {
                // TODO: SDL_Display resize
            }

            // Update the display
            void Refresh() {
                SDL_RenderPresent(renderTarget);
            }

            // Clear the display
            void Clear() {
                SDL_RenderClear(renderTarget);
            }

            // Set background color
            void SetBackgroundColor() {
                // TODO: Color
            }

            // Destructor destroys display
            ~Display() {
                // TODO: dtor
                SDL_DestroyWindow(window);
                SDL_Quit();
            }

            SDL_Window* GetWindow() {
                return window;
            }

            // SDL_Surface* GetWindowSurface() {
            //     return screenSurface;
            // }

            SDL_Renderer* GetRenderer() {
                return renderTarget;
            }

        private:
            SDL_Window* window = nullptr;
            //SDL_Surface* screenSurface = nullptr;
            SDL_Renderer* renderTarget = nullptr;
            int width, height;
        };
    }
}

#endif /* Display_hpp */
