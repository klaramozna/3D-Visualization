#ifndef INC_3DSDL_POINT_H
#define INC_3DSDL_POINT_H

#include "Matrix.h"

class Point {
public:
    Point(): x(0), y(0), z(0){};
    Point(double x, double y, double z = 0){this->x = x; this->y = y; this->z = z;};
    double getX() const {return x;};
    double getY() const {return y;};
    double getZ() const {return z;};
    void setX(double val) {this->x = val;};
    void setY(double val) {this->y = val;};
    void setZ(double val) {this->z = val;};
    Point(Matrix m);
private:
    double x;
    double y;
    double z;
};


#endif //INC_3DSDL_POINT_H
