#ifndef INC_3DSDL1_CONTROLS_H
#define INC_3DSDL1_CONTROLS_H

#include "Camera.h"
#include "Screen.h"

class Controls {
public:
    Controls(const Screen& s, const Camera& c);
    void handleInput();
private:
    Screen screen;
    Camera camera;
};


#endif //INC_3DSDL1_CONTROLS_H
