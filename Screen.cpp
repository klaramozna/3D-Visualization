#include "Screen.h"
#include "SDL2/SDL.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Screen::Screen() {
    // TODO: error handling
    window = SDL_CreateWindow("3D Animation",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

Screen::~Screen() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Screen::updateScreen() {
    SDL_RenderPresent(renderer);
}

void Screen::clearScreen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void Screen::drawPoint(Point point) {
    SDL_RenderDrawPoint(renderer, static_cast<int>(point.getX()), static_cast<int>(point.getY()));
}

void Screen::drawLine(Point p1, Point p2) {
    SDL_RenderDrawLine(renderer, static_cast<int>(p1.getX()), static_cast<int>(p1.getY()), static_cast<int>(p2.getX()), static_cast<int>(p2.getY()));
}
