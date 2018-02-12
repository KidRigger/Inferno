#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "inferno/graphics/Display.hpp"
#include "inferno/graphics/Texture.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;

bool init();
void close();
void refresh();

int main(int argc, char* argv[]) {

    inferno::graphics::Display disp(640,480);

    inferno::graphics::TextureHandle h1 = std::make_shared<inferno::graphics::Texture>(disp.GetRenderer(),"../character_hurt.png","charhurt");

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
        SDL_RenderCopy(disp.GetRenderer(), h1->GetTexture(), h1->GetQuad().GetRect(), NULL);
        disp.Refresh();
        SDL_Delay(200);
    }

    return 0;
}
