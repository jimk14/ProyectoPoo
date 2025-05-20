#include <SFML/Graphics.hpp>
#include <string>
#include "Hormiga.h"


Hormiga::Hormiga(int energia, int ataque, int vitalidad, sf::Vector2f posicion): HormigaSprite(HormigaSprite) {
    this->energia = energia;
    this->ataque = ataque;
    this->vitalidad = vitalidad;
    this->posicion = posicion;
}

void Hormiga::cargartextura(const string&) {
    if (!HormigaNormal.loadFromFile("Hormiganormal.png")) {
        return ;
    }
    HormigaSprite.setTexture(HormigaNormal);
    actualizarsprite();
}

void Hormiga::actualizarsprite() {
    HormigaSprite.setPosition(posicion);
}

// Getters
int Hormiga::getEnergia() const {
    return energia;
}
int Hormiga::getAtaque() const {
    return ataque;
}
int Hormiga::getVitalidad() const {
    return vitalidad;
}
sf::Vector2f Hormiga::getPosicion() const {
    return posicion;
}


// Setters
void Hormiga::setEnergia(int energia) {
    this->energia = energia;
}
void Hormiga::setAtaque(int ataque) {
    this->ataque = ataque;
}
void Hormiga::setVitalidad(int vitalidad) {
    this->vitalidad = vitalidad;
}
void Hormiga::setPosicion(sf::Vector2f posicion) {
    this->posicion = posicion;
}
