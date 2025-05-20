#include <SFML/Graphics.hpp>
#include "Ray.cpp"


int main()
{

    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    window.setFramerateLimit(60);
    sf::Texture texture;
    sf::RectangleShape rectangle({100,150});
    rectangle.setTexture(&texture);
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(sf::Vector2f(400, 300));

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.draw(rectangle);
        window.display();
    }
    return 0;
}
