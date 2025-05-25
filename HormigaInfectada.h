#ifndef HORMIGAINFECTADA_H
#define HORMIGAINFECTADA_H

#include "Hormiga.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class HormigaInfectada : public Hormiga {
private:
    std::vector<sf::Texture> texturasInfectada;
    int estadoActual;
    float tiempoCambio;
    sf::Clock reloj;

public:
    HormigaInfectada(int vitalidad, sf::Vector2f posicion);

    void cargarTexturas();
    void cambiarEstado();
    void mover();
    void atacar();
    void actualizarSprite();
};

#endif
