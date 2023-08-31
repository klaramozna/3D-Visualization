#ifndef INC_3DSDL1_ANIMATION_H
#define INC_3DSDL1_ANIMATION_H

#include "Screen.h"
#include "Camera.h"


class Animation {
public:
    Animation(const Screen& s, const Camera& c, const std::vector<Point>& points, const std::vector<std::pair<Point, Point>>& lines);
private:
    std::vector<Point> points;
    std::vector<std::pair<Point, Point>> lines;
};


#endif //INC_3DSDL1_ANIMATION_H
