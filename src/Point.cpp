#include "Point.h"

Point::Point() = default;

Point::Point(Float x, Float y): rx(x), ry(y) {}

Float Point::get_x() {return rx;}

Float Point::get_y() {return ry;}


void Point::set_x(Float _x) {rx = _x;}

void Point::set_y(Float _y) {ry = _y;}