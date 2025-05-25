#ifndef MAPADEJUEGO_H
#define MAPADEJUEGO_H

#include <SFML/Graphics.hpp>
#include "ray.h"

class MapaDeJuego {
public:
    MapaDeJuego(sf::RenderWindow& ventana, Ray& jugador);
    bool estaAbierto() const;
    void procesarEventos();
    void actualizar();
    void dibujar();

private:
    sf::RenderWindow& window;
    Ray& ray;
    sf::Sprite fondo;
    sf::Texture textura1, textura2, textura3,textura4;
    int enFondo = 1;
    const float gravedad = 0.5f;
    float sueloY;
};

#endif
