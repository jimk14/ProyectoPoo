//
// Created by javiu on 24/05/2025.
//
#include "Personaje.h"

Personaje::Personaje() {
    velocidad = 7.f;
    velocidadVertical = 0.f;
    enSuelo = true;
    vida = 100;
    cuerpo.setSize({350, 400});
    cuerpo.setFillColor(sf::Color::White);
    cuerpo.setPosition({0, 600});
}

void Personaje::actualizar() {
    velocidadVertical += gravedad;
    cuerpo.move({0, velocidadVertical});

    if (cuerpo.getPosition().y + cuerpo.getSize().y >= 1000 - 50) {
        cuerpo.setPosition({cuerpo.getPosition().x, 1000 - 50 - cuerpo.getSize().y});
        velocidadVertical = 0;
        enSuelo = true;
    }
}

void Personaje::dibujar(sf::RenderWindow& window) {
    window.draw(cuerpo);
}

void Personaje::recibirDanio(int cantidad) {
    vida -= cantidad;
    if (vida < 0) vida = 0;
}

void Personaje::curar(int cantidad) {
    vida += cantidad;
    if (vida > 100) vida = 100;
}

sf::FloatRect Personaje::getBounds() const {
    return cuerpo.getGlobalBounds();
}

bool Personaje::estaVivo() const {
    return vida > 0;
}
