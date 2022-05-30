#include "../libs.h"

class Button {
    public:
        Button() {}

        Button(std::string t, sf::Vector2f size, sf::Color bgColor, sf::Color textColor) {
            text.setString(t);
            button.setSize(size);

            button.setSize(size);
            button.setFillColor(bgColor);
        }
    private:
        sf::RectangleShape button;
        sf::Text text;
        
}