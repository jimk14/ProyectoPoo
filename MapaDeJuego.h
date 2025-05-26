#ifndef MAPADEJUEGO_H
#define MAPADEJUEGO_H

#include <SFML/Graphics.hpp>
#include "Ray.h"

class MapaDeJuego {
private:
    sf::Sprite fondo;
    sf::Texture textura1, textura2, textura3, textura4;
    int enFondo;

public:
    MapaDeJuego();  // Constructor sin parámetros
    void actualizar(const Ray& ray);  // Actualiza el fondo según la posición de Ray
    void dibujar(sf::RenderWindow& window);  // Dibuja el fondo
};

#endif
