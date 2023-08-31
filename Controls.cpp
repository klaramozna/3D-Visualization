#include "Controls.h"

#include <utility>
#include "SDL2/SDL.h"

Controls::Controls(const Screen& s, const Camera& c) {
    screen = s;
    camera = c;
}

void Controls::handleInput() {
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_KEYDOWN){
            handleKeys(event);
        }
    }
}

void Controls::handleKeys(const SDL_Event &event) {
    // TODO: seconds and move speed
    double moveSpeed = 1;
    int seconds = 1000;
    switch (event.key.keysym.sym) {
        case SDLK_w:
            camera.moveForward(moveSpeed);
            screen.updateScreen()
            SDL_Delay(seconds);
        case SDLK_a:
            camera.moveLeft(moveSpeed);
            SDL_Delay(seconds);
        case SDLK_d:
            camera.moveRight(moveSpeed);
            SDL_Delay(seconds);
        case SDLK_s:
            camera.moveBackward(moveSpeed);
            SDL_Delay(seconds);

    }
}
