#ifndef INC_3DSDL_SCREEN_H
#define INC_3DSDL_SCREEN_H

#include <SDL2/SDL.h>
#include "Point.h"


class Screen {
public:
    Screen();
    ~Screen();
    void drawPoint(Point point);
    void drawLine(Point p1, Point p2);
    void clearScreen();
    void updateScreen();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};


#endif //INC_3DSDL_SCREEN_H
