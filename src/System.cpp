    #include "Collision_System.h"
#include "quadtree.h"

system::system(sf::RenderWindow* wnd, int num): window(wnd){
    Particles particles;
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

            
        }
        //window->clear();
        particles.draw(window);
        window->display();
    }
}