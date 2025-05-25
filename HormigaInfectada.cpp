#include "HormigaInfectada.h"
#include <cstdlib>

HormigaInfectada::HormigaInfectada(int vitalidad, sf::Vector2f posicion)
    : Hormiga(80, 10, vitalidad, posicion) {
    estadoActual = 0;
    tiempoCambio = 1.0f;
    cargarTexturas();
    actualizarSprite();
}

void HormigaInfectada::cargarTexturas() {
    sf::Texture temp;


    temp.loadFromFile("infectada 1.png");
    texturasInfectada.push_back(temp);

    // estado 1: atacando
    temp.loadFromFile("infectada 2.png");
    texturasInfectada.push_back(temp);

    // estado 2: liberando esporas
    temp.loadFromFile("Infectada 3.png");
    texturasInfectada.push_back(temp);

    HormigaSprite.setTexture(texturasInfectada[estadoActual]);
}

void HormigaInfectada::cambiarEstado() {
    if (reloj.getElapsedTime().asSeconds() >= tiempoCambio) {
        estadoActual = (estadoActual + 1) % texturasInfectada.size();
        HormigaSprite.setTexture(texturasInfectada[estadoActual]);
        reloj.restart();
    }
}

void HormigaInfectada::mover() {
    float dx = (rand() % 3 - 1) * 2.0f;
    float dy = (rand() % 3 - 1) * 2.0f;
    posicion.x += dx;
    posicion.y += dy;
    actualizarSprite();
}

void HormigaInfectada::atacar() {
    estadoActual = 1;
    HormigaSprite.setTexture(texturasInfectada[estadoActual]);
}

void HormigaInfectada::actualizarSprite() {
    HormigaSprite.setPosition(posicion);
}
