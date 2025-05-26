#include "HormigaInfectada.h"
#include <iostream>

HormigaInfectada::HormigaInfectada(): sprite(sprite) {
    if (!texturaViva.loadFromFile("assets/infectada 1.png"))
        std::cerr << "Error al cargar infectada 1.png\n";

    if (!texturaAtaque.loadFromFile("assets/Infectada 3.png"))
        std::cerr << "Error al cargar Infectada 3.png\n";

    if (!texturaMuerta.loadFromFile("assets/infectada 4.png"))
        std::cerr << "Error al cargar infectada 4.png\n";

    sprite.setTexture(texturaViva);
    posicion = sf::Vector2f(50, 300);
    sprite.setPosition(posicion);

    velocidad = 1.0f;
    vida = 1;
    viva = true;
}

void HormigaInfectada::actualizar() {
    if (!viva) return;

    posicion.x += velocidad;
    sprite.setPosition(posicion);

    if (rand() % 100 < 2) {
        atacar();
    } else {
        sprite.setTexture(texturaViva); 
    }
}

void HormigaInfectada::dibujar(sf::RenderWindow &ventana) {
    ventana.draw(sprite);
}

void HormigaInfectada::atacar() {
    sprite.setTexture(texturaAtaque); 
    std::cout << "La hormiga infectada ataca con esporas tóxicas." << std::endl;
}

bool HormigaInfectada::estaViva() const {
    return viva;
}

void HormigaInfectada::recibirDano(int cantidad) {
    vida -= cantidad;
    if (vida <= 0) {
        viva = false;
        sprite.setTexture(texturaMuerta); 
        std::cout << "¡Hormiga infectada eliminada!" << std::endl;
    }
}

void HormigaInfectada::mostrarBarraVida() {
    std::cout << "[VIDA INFECTADA]: ";
    if (vida > 0)
        std::cout << "|#|" << std::endl;
    else
        std::cout << "| | (muerta)" << std::endl;
}
