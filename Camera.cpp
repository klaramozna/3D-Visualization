//
// Created by klara on 22.08.2023.
//

#include "Camera.h"
#include <vector>
#include <cmath>

Camera::Camera(int pixelWidth, int pixelHeight) {
    this->pixelWidth = pixelWidth;
    this->pixelHeight = pixelHeight;
    std::vector<double> values {1, 0, 0, 0,
                                0, 1, 0, 0,
                                0, 0, 1, 0,
                                0, 0, 0, 1};
    cameraToWorld = Matrix(4, 4, values.begin(), values.end());
    worldToCamera = cameraToWorld;
    if(pixelWidth >= pixelHeight){
        canvasHeight = 1.0;
        canvasWidth = static_cast<double>(pixelWidth) / static_cast<double>(pixelHeight);
    }
    else{
        canvasWidth = 1.0;
        canvasHeight = static_cast<double>(pixelHeight) / static_cast<double>(pixelWidth);
    }
    distanceToCanvas = 1;
}

Point Camera::getCanvasCoordinates(Point point) const {
    // express point in world-coordinates in camera-coordinates
    Point pointInCameraCoordinates = point;
    std::vector<double> v {point.getX(), point.getY(), point.getZ(), 1};
    Matrix pointAsMatrix = Matrix(1, 4, v.begin(), v.end());
    Matrix m = worldToCamera * pointAsMatrix;
    pointInCameraCoordinates.setX(m.getValueAt(0, 0) /*/ m.getValueAt(3, 0)*/);
    pointInCameraCoordinates.setY(m.getValueAt(1, 0) /*/ m.getValueAt(3, 0)*/);
    pointInCameraCoordinates.setZ(m.getValueAt(2,  0) /*/ m.getValueAt(3, 0)*/);

    // calculate point on the screen
    double newX = pointInCameraCoordinates.getX()/((-1.0) * pointInCameraCoordinates.getZ()) * distanceToCanvas;
    double newY = pointInCameraCoordinates.getY()/((-1.0) * pointInCameraCoordinates.getZ()) * distanceToCanvas;
    Point pointInScreenSpace(newX, newY);

    // calculate point in pixel coordinates
    Point pointInNDCSpace = convertToNDC(pointInScreenSpace);
    Point pointInRasterSpace = convertToRaster(pointInNDCSpace);
    return pointInRasterSpace;
}

Point Camera::convertToNDC(Point point) const {
    point.setX((point.getX() + canvasWidth/2.0) / canvasWidth);
    point.setY((point.getY() + canvasHeight/2.0) / canvasHeight);
    return point;
}

Point Camera::convertToRaster(Point point) const {
    point.setX(std::floor(point.getX() * pixelWidth));
    point.setY(std::floor((1 - point.getY()) * pixelHeight));
    return point;
}

std::vector<Point> Camera::getCanvasCoordinates(const std::vector<Point> &points) const {
    std::vector<Point> transformed;
    transformed.reserve(points.size());
    for(const auto & point : points){
        transformed.push_back(getCanvasCoordinates(point));
    }
    return transformed;
}

void Camera::moveUp(double distance) {
    cameraToWorld.setValueAt(1, 3, cameraToWorld.getValueAt(1, 3) + distance);
    worldToCamera = cameraToWorld.getInverse();
}

void Camera::moveDown(double distance) {
    cameraToWorld.setValueAt(1, 3, cameraToWorld.getValueAt(1, 3) - distance);
    worldToCamera = cameraToWorld.getInverse();
}

void Camera::moveRight(double distance) {
    cameraToWorld.setValueAt(0, 3, cameraToWorld.getValueAt(0, 3) + distance);
    worldToCamera = cameraToWorld.getInverse();
}

void Camera::moveLeft(double distance) {
    cameraToWorld.setValueAt(0, 3, cameraToWorld.getValueAt(0, 3) - distance);
    worldToCamera = cameraToWorld.getInverse();
}

void Camera::moveBackward(double distance) {
    cameraToWorld.setValueAt(2, 3, cameraToWorld.getValueAt(2, 3) + distance);
    worldToCamera = cameraToWorld.getInverse();
}

void Camera::moveForward(double distance) {
    cameraToWorld.setValueAt(2, 3, cameraToWorld.getValueAt(2, 3) - distance);
    worldToCamera = cameraToWorld.getInverse();
}

Camera::Camera() {
    // TODO: define width and height as constants
    pixelWidth = 640;
    pixelHeight = 480;
    std::vector<double> values {1, 0, 0, 0,
                                0, 1, 0, 0,
                                0, 0, 1, 0,
                                0, 0, 0, 1};
    cameraToWorld = Matrix(4, 4, values.begin(), values.end());
    worldToCamera = cameraToWorld;
    if(pixelWidth >= pixelHeight){
        canvasHeight = 1.0;
        canvasWidth = static_cast<double>(pixelWidth) / static_cast<double>(pixelHeight);
    }
    else{
        canvasWidth = 1.0;
        canvasHeight = static_cast<double>(pixelHeight) / static_cast<double>(pixelWidth);
    }
    distanceToCanvas = 1;
}
