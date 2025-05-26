#include "MapaDeJuego.h"
#include <iostream>

MapaDeJuego::MapaDeJuego(): fondo(fondo), enFondo(1) {
    if (!textura1.loadFromFile("npc.png"))
        std::cerr << "No se pudo cargar npc.png\n";
    if (!textura2.loadFromFile("pasillo.jpg"))
        std::cerr << "No se pudo cargar pasillo.jpg\n";
    if (!textura3.loadFromFile("antesala.jpg"))
        std::cerr << "No se pudo cargar antesala.jpg\n";
    if (!textura4.loadFromFile("sala.jpg"))
        std::cerr << "No se pudo cargar sala.jpg\n";

    fondo.setTexture(textura1);
}

void MapaDeJuego::actualizar(const Ray& ray) {
    sf::Vector2f pos = ray.getPosicion();

    if (pos.x > 1900.f) {  // Tamaño de la ventana (ajústalo si cambia)
        if (enFondo == 1) {
            fondo.setTexture(textura2);
            enFondo = 2;
        } else if (enFondo == 2) {
            fondo.setTexture(textura3);
            enFondo = 3;
        } else if (enFondo == 3) {
            fondo.setTexture(textura4);
            enFondo = 4;
        }
    }

    // Ajustar escala para cubrir ventana
    auto size = fondo.getTexture().getSize();
    fondo.setScale(sf::Vector2f(1000.0f / size.x, 1000.0f / size.y));
    fondo.setPosition(sf::Vector2f(0.0f,0.0f));
}

void MapaDeJuego::dibujar(sf::RenderWindow& window) {
    window.draw(fondo);
}
