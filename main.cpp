#include <SFML/Graphics.hpp>
#include "Ray.h"
#include "MapaDeJuego.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({1900, 1000}), "Ray: El Explorador");
    window.setFramerateLimit(60);

    Ray ray;
    MapaDeJuego mapa;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        ray.manejarEntrada();
        ray.actualizar();

        mapa.actualizar(ray);        // El mapa cambia de fondo si Ray se mueve
        window.clear();
        mapa.dibujar(window);
        ray.dibujar(window);
        window.display();
    }

    return 0;
}
