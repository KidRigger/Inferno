#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;

bool init();
void close();
void refresh();

int main(int argc, char* argv[]) {

    if (!init()) {
        return 1;
    }
    SDL_Surface* pngSurface = nullptr;
    pngSurface = IMG_Load("../character_hurt.png");
    if (pngSurface == nullptr) {
        return 1;
    }

    SDL_Event ev;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&ev) != 0) {
            if(ev.type == SDL_QUIT) {
                running = false;
            }
        }
        SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
        refresh();
        SDL_BlitSurface(pngSurface, NULL, screenSurface, NULL);
        refresh();
    }

    SDL_FreeSurface(pngSurface);
    close();
    return 0;
}

bool init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL could not initialize. " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        std::cerr << "Window could not be opened." << SDL_GetError() << std::endl;
        return false;
    }

    screenSurface = SDL_GetWindowSurface(window);
    return true;
}

void refresh() {
    SDL_UpdateWindowSurface(window);
    SDL_Delay(200);
}

void close() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
