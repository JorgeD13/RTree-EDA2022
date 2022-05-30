#ifndef SYSTEM_H
#define SYSTEM_H

#include "Points.h"
#include "Rtree/rtree.h"
#include "libs.h"

class System {
private:
    sf::RenderWindow* window{};
public:
    System();
    explicit System(sf::RenderWindow* wnd);
};

#endif