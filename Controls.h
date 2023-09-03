#ifndef INC_3DSDL1_CONTROLS_H
#define INC_3DSDL1_CONTROLS_H

#include "Animation.h"

class Controls {
public:
    explicit Controls(const Animation& a);
    void handleInput();
private:
    Animation animation;
    void handleKeys(const SDL_Event& event);
};


#endif //INC_3DSDL1_CONTROLS_H
