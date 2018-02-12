#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "inferno/graphics/Display.hpp"
#include "inferno/graphics/Texture.hpp"
#include "inferno/graphics/TextureManager.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;

bool init();
void close();
void refresh();

int main(int argc, char* argv[]) {

    inferno::graphics::Display disp(640,480);

    inferno::graphics::TextureManager tm(disp.GetRenderer());
    tm.Load("../character_hurt.png","charhurt");
    inferno::graphics::TextureHandle h1 = tm["charhurt"];

    SDL_Event ev;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&ev) != 0) {
            if(ev.type == SDL_QUIT) {
                running = false;
            }
        }
        disp.Clear();
        disp.Refresh();
        SDL_Delay(200);
        SDL_RenderCopy(disp.GetRenderer(), h1->GetTexture(),  NULL, h1->GetQuad().GetRect());
        disp.Refresh();
        SDL_Delay(200);
    }

    return 0;
}
