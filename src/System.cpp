#include "System.h"

System::System() = default;

System::System(sf::RenderWindow* wnd) : window(wnd) {
    Points points;
    //auto wndsize = window->getSize();
    
    // QuadTree qt(0, wndsize.x, 0, wndsize.y);
    // Inicializar Rtree
    sf::Vector2i mousep = sf::Mouse::getPosition(*window);
    sf::Mouse::setPosition(mousep, *window);
    while (window->isOpen())
    {
        sf::Event event{};
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            // evento de click
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i position = sf::Mouse::getPosition();
                Point p(position.x-6, position.y-60);
                points.add(p);
            }
            
        }
        //window->clear();
        points.draw(window);
        window->display();
    }
}