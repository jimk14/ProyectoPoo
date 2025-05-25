#include "mapadejuego.h"
#include "ray.h"
#include <SFML/Graphics.hpp>

MapaDeJuego::MapaDeJuego(sf::RenderWindow& ventana, Ray& jugador)
    : window(ventana), ray(jugador), enFondo(), fondo(fondo)
{



    sueloY = static_cast<float>(window.getSize().y) - 150.0f; // altura de Ray
}

bool MapaDeJuego::estaAbierto() const {
    return window.isOpen();
}

void MapaDeJuego::procesarEventos() {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
    }
}
void MapaDeJuego::actualizar() {
    sf::Sprite sprite(textura1);

    float scaleX = static_cast<float>(window.getSize().x) / textura1.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / textura1.getSize().y;
    sprite.setScale({scaleX,scaleY});
    sprite.setPosition(sf::Vector2f(0, 0));

    textura1.loadFromFile("npc.png");
    textura2.loadFromFile("pasillo.jpg");
    textura3.loadFromFile("antesala.jpg");
    textura4.loadFromFile("sala.jpg");



    sf::Vector2f pos = ray.getPosicion();

    if (pos.x > window.getSize().x) {
        if (enFondo == 1) {
            sprite.setTexture(textura2);
            enFondo = 2;
            ray.setPosicion({0, pos.y});
        } else if (enFondo == 2) {
            sprite.setTexture(textura3);
            enFondo = 3;
            ray.setPosicion({0, pos.y});
        }
    }
}
void MapaDeJuego::dibujar() {
    window.clear();
    window.draw(fondo);
    ray.dibujar(window);
    window.display();
}
