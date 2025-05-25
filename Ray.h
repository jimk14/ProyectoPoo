#ifndef RAY_H
#define RAY_H

#include "Hormiga.h"
#include <SFML/Graphics.hpp>

class Ray : public Hormiga {
private:
    void cargarTexturaRay();
    float velocity = 5;
public:
    Ray(int vitalidad, sf::Vector2f posicion);
    void dibujar (sf::RenderWindow& window);

    void mover(const std::string& direccion);
    void actualizarSprite();

    // Métodos específicos de Ray
    void usarSuperColpedeLuz();
    void usarBaston();
};

#endif // RAY_H
