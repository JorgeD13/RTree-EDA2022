#ifndef POINTS_H
#define POINTS_H

#include "Point.h"

class Points{
    int number_of_points;
    vector<Point> points;

public:
    Points();
    explicit Points(int quantity);

    void draw(sf::RenderWindow* window);
    void move();
    vector<Point> get_points();

};


#endif