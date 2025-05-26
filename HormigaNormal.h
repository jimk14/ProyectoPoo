#ifndef HORMIGANORMAL_H
#define HORMIGANORMAL_H

#include "Hormiga.h"
#include "Ray.h"
#include <SFML/Graphics.hpp>
#include <string>

class HormigaNormal : public Hormiga {
private:
    bool yaInteractuo = false;

public:
    HormigaNormal(int energia, int ataque, int vitalidad, sf::Vector2f posicion);

    void dibujar(sf::RenderWindow& ventana);
    void interactuar(Ray& ray);
    bool colisionaConRay(const sf::FloatRect& rayRect) const;
};


#endif //HORMIGANORMAL_H
