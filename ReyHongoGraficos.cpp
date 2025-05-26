#include "ReyHongoGraficos.h"

ReyHongoGrafico::ReyHongoGrafico(sf::Vector2f posicionInicial): hongoSprite(hongoSprite) {
    posicion = posicionInicial;
    estadoActual = 0;
    vidaMaxima = 100;

    cargarTexturas();
    actualizarSprite();

    // Configuracion barra de vida
    barraVidaFondo.setSize(sf::Vector2f(100.f, 10.f));
    barraVidaFondo.setFillColor(sf::Color(100, 100, 100)); // gris oscuro
    barraVidaFondo.setPosition({posicion.x, posicion.y - 20.f});

    barraVida.setSize(sf::Vector2f(100.f, 10.f));
    barraVida.setFillColor(sf::Color::Green); // verde
    barraVida.setPosition({posicion.x, posicion.y - 20.f});
}

void ReyHongoGrafico::cargarTexturas() {
    sf::Texture temp;

    // Estado 0 - normal
    temp.loadFromFile("bin/rey_hongo.png");
    texturasHongo.push_back(temp);

    // Estado 1 - atacando
    temp.loadFromFile("bin/rey_hongo_atacando.png");
    texturasHongo.push_back(temp);

    // Estado 2 - dañado
    temp.loadFromFile("bin/rey_hongo_danado.png");
    texturasHongo.push_back(temp);

    hongoSprite.setTexture(texturasHongo[estadoActual]);
}

void ReyHongoGrafico::atacar() {
    estadoActual = 1;
    hongoSprite.setTexture(texturasHongo[estadoActual]);
}

void ReyHongoGrafico::recibirDanio() {
    estadoActual = 2;
    hongoSprite.setTexture(texturasHongo[estadoActual]);
}

void ReyHongoGrafico::actualizarVida(int vidaActual) {
    float porcentaje = static_cast<float>(vidaActual) / vidaMaxima;
    barraVida.setSize(sf::Vector2f(100.f * porcentaje, 10.f));
}

void ReyHongoGrafico::actualizarSprite() {
    hongoSprite.setPosition(posicion);
    barraVida.setPosition({posicion.x, posicion.y - 20.f});
    barraVidaFondo.setPosition({posicion.x, posicion.y - 20.f});
}

void ReyHongoGrafico::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(hongoSprite);
    ventana.draw(barraVidaFondo);
    ventana.draw(barraVida);
}