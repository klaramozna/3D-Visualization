#ifndef INC_3DSDL1_ANIMATION_H
#define INC_3DSDL1_ANIMATION_H

#include "Screen.h"
#include "Camera.h"
#include "Point.h"


class Animation {
public:
    Animation(const Screen& s, const Camera& c, const std::vector<Point>& points,
              const std::vector<std::pair<Point, Point>>& lines, int delayMilliseconds, double distance);
    Animation(const Screen& s, const Camera& c, int delayMilliseconds, double distance);
    Animation(const Screen& s, const Camera& c);
    Animation() = default;
    void addPoint(Point p);
    void addLine(std::pair<Point, Point> line);
    template<class Iterator> void addPoints(Iterator begin, Iterator end);
    template<class Iterator> void addLines(Iterator begin, Iterator end);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void moveForward();
    void moveBackward();
private:
    std::vector<Point> points;
    std::vector<std::pair<Point, Point>> lines;
    int delayMilliseconds;
    double distance;
    Screen screen;
    Camera camera;
    void displayState();
    void updateCoordinates();
};


#endif //INC_3DSDL1_ANIMATION_H
