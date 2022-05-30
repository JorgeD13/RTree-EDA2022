#include "libs.h"
#include "System.h"

#define width 900
#define height 500

int main() {

    sf::RenderWindow window(sf::VideoMode(width, height), "RTree");
    System o(&window);

    return 0;
}