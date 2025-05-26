#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>

class Personaje {
protected:
    sf::RectangleShape cuerpo;
    int vida;
    float velocidad;
    float velocidadVertical;
    bool enSuelo;
    const float gravedad = 0.5f;
    const float salto = -12.f;

public:
    Personaje();
    virtual void manejarEntrada() = 0;
    virtual void actualizar();
    virtual void dibujar(sf::RenderWindow& window);
    virtual void recibirDanio(int cantidad);
    virtual void curar(int cantidad);
    sf::FloatRect getBounds() const;
    bool estaVivo() const;
};

#endif
