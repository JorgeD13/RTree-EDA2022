#include "System.h"
#include "Rtree/rtree.h"

System::System() = default;

System::System(sf::RenderWindow* wnd) : window(wnd) {
    Points points;
    auto wndsize = window->getSize();
    
    // QuadTree qt(0, wndsize.x, 0, wndsize.y);
    // Inicializar Rtree

    while (window->isOpen())
    {
        sf::Event event{};
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            // evento de click
            // evento de click
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i position = sf::Mouse::getPosition();
                Point p(position.x, position.y);
            }
            
        }
        //window->clear();
        points.draw(window);
        window->display();
    }
}