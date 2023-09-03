//
// Created by klara on 31.08.2023.
//

#include "Animation.h"

const int defaultDelay = 1000;
const double defaultDistance = 1;

Animation::Animation(const Screen &s, const Camera &c, const std::vector<Point> &points,
                     const std::vector<std::pair<Point, Point>> &lines, int delayMilliseconds = defaultDelay, double distance = defaultDistance) {
    screen = s;
    camera = c;
    this->points = points;
    this->lines = lines;
    this->delayMilliseconds = delayMilliseconds;
    this->distance = distance;
}

Animation::Animation(const Screen &s, const Camera &c) {
    screen = s;
    camera = c;
    this->delayMilliseconds = defaultDelay;
    this->distance = defaultDistance;
}

void Animation::addPoint(Point p) {
    points.push_back(p);
}

void Animation::addLine(std::pair<Point, Point> line) {
    lines.push_back(line);
}

template<class Iterator>
void Animation::addPoints(Iterator begin, Iterator end) {
    points.insert(points.end(), begin, end);
}

template<class Iterator>
void Animation::addLines(Iterator begin, Iterator end) {
    lines.insert(lines.end(), begin, end);
}

void Animation::moveLeft() {
    camera.moveLeft(distance);
    updateCoordinates();
    displayState();
    SDL_Delay(delayMilliseconds);
}

void Animation::displayState() {
    screen.clearScreen();
    for(auto & point : points){
        screen.drawPoint(point);
    }
    for(auto & line : lines){
        screen.drawLine(line.first, line.second);
    }
    screen.updateScreen();
}

void Animation::updateCoordinates() {
    points = camera.getCanvasCoordinates(points);
    for(auto & line : lines){
        line.first = camera.getCanvasCoordinates(line.first);
        line.second = camera.getCanvasCoordinates(line.second);
    }
}

void Animation::moveRight() {
    camera.moveRight(distance);
    updateCoordinates();
    displayState();
    SDL_Delay(delayMilliseconds);
}

void Animation::moveUp() {
    camera.moveUp(distance);
    updateCoordinates();
    displayState();
    SDL_Delay(delayMilliseconds);
}

void Animation::moveDown() {
    camera.moveDown(distance);
    updateCoordinates();
    displayState();
    SDL_Delay(delayMilliseconds);
}

void Animation::moveForward() {
    camera.moveForward(distance);
    updateCoordinates();
    displayState();
    SDL_Delay(delayMilliseconds);
}

void Animation::moveBackward() {
    camera.moveBackward(distance);
    updateCoordinates();
    displayState();
    SDL_Delay(delayMilliseconds);
}

Animation::Animation(const Screen &s, const Camera &c, int delayMilliseconds, double distance) {
    screen = s;
    camera = c;
    this->delayMilliseconds = delayMilliseconds;
    this->distance = distance;
}


