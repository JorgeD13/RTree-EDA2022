#ifndef SYSTEM_H
#define SYSTEM_H

#include "Particles.h"

class system {
private:
    sf::RenderWindow* window{};
public:
    system(sf::RenderWindow* wnd);
};

#endif