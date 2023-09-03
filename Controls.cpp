#include "Controls.h"

#include "SDL2/SDL.h"

Controls::Controls(const Animation& a) {
    animation = a;
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
    switch (event.key.keysym.sym) {
        case SDLK_w:
            animation.moveForward();
            break;
        case SDLK_a:
            animation.moveLeft();
            break;
        case SDLK_d:
            animation.moveRight();
            break;
        case SDLK_s:
            animation.moveBackward();
            break;
        case SDLK_UP:
            animation.moveUp();
            break;
        case SDLK_DOWN:
            animation.moveDown();
            break;
    }
}
