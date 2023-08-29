#ifndef INC_3DSDL_CAMERA_H
#define INC_3DSDL_CAMERA_H

#include "Matrix.h"
#include "Point.h"
#include <vector>


class Camera {
public:
    Camera(Matrix cameraToWorld, int canvasWidth, int canvasHeight);
    Camera(int canvasWidth, int canvasHeight);
    Point getCanvasCoordinates(Point point) const;
    std::vector<Point> getCanvasCoordinates(const std::vector<Point>& points) const;
    void changeCameraPosition(Matrix cameraToWorld);
    void rotateUp(double angle);
    void rotateDown(double angle);
    void rotateLeft(double angle);
    void rotateRight(double angle);
    void moveForward(double distance);
    void moveBackward(double distance);
    void moveUp(double distance);
    void moveDown(double distance);
    void moveRight(double distance);
    void moveLeft(double distance);
private:
    int pixelWidth;
    int pixelHeight;
    double canvasWidth;
    double canvasHeight;
    double distanceToCanvas;
    Matrix cameraToWorld;
    Matrix worldToCamera;
    Point convertToNDC(Point point) const;
    Point convertToRaster(Point point) const;
};

#endif //INC_3DSDL_CAMERA_H
