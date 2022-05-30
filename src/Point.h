#ifndef POINT_H
#define POINT_H

#include "libs.h"

class Point {
    Float rx, ry;
    // Float vx, vy;

public:
    Point();
    Point(Float x, Float y);

    Float get_x();
    Float get_y();
    // Float get_vx();
    // Float get_vy();

    void set_x(Float _x);
    void set_y(Float _y);
    // void set_vx(Float _vx);
    // void set_vy(Float _vy);
};

#endif  