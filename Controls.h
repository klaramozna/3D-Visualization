#ifndef INC_3DSDL1_CONTROLS_H
#define INC_3DSDL1_CONTROLS_H

#include "Camera.h"
#include "Screen.h"
#include "Point.h"

class Controls {
public:
    Controls(const Screen& s, const Camera& c);
    void handleInput();
private:
    Screen screen;
    Camera camera;
    void handleKeys(const SDL_Event& event);
};


#endif //INC_3DSDL1_CONTROLS_H
