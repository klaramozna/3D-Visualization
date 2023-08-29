#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "Screen.h"
#include "Camera.h"
#include "Point.h"
#include <unistd.h>

std::vector<Point> createRectangle(Point corner, int size){
    std::vector<Point> v {corner, Point(corner.getX()+size, corner.getY(), corner.getZ()), Point(corner.getX()+size, corner.getY()+size, corner.getZ()), Point(corner.getX(), corner.getY()+size, corner.getZ()),
            Point(corner.getX(), corner.getY(), corner.getZ()-size), Point(corner.getX()+size, corner.getY(), corner.getZ()-size), Point(corner.getX()+size, corner.getY()+size, corner.getZ()-size), Point(corner.getX(), corner.getY()+size, corner.getZ()-size)};
    return v;
}

void connectRectangle(std::vector<Point> v, Screen& s){
    s.drawLine(v[0], v[1]);
    s.drawLine(v[1], v[2]);
    s.drawLine(v[2], v[3]);
    s.drawLine(v[3], v[0]);

    s.drawLine(v[4], v[5]);
    s.drawLine(v[5], v[6]);
    s.drawLine(v[6], v[7]);
    s.drawLine(v[7], v[4]);

    s.drawLine(v[0], v[4]);
    s.drawLine(v[1], v[5]);
    s.drawLine(v[2], v[6]);
    s.drawLine(v[3], v[7]);
    s.updateScreen();
}

int main() {
    Screen s = Screen();
    Camera c(640, 480);
    std::vector<Point> v = createRectangle(Point(-1,-1, -20), 10);
    std::vector<Point> perspective = c.getCanvasCoordinates(v);
    connectRectangle(perspective, s);
    c.moveForward(10);
    perspective = c.getCanvasCoordinates(v);
    connectRectangle(perspective, s);

    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
        }
    }
    return 0;
}