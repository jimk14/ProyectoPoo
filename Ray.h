#ifndef RAY_H
#define RAY_H

#include "Hormiga.h"
#include <SFML/Graphics.hpp>

class Ray : public Hormiga {
private:
    void cargarTexturaRay();

public:
    Ray(int vitalidad, sf::Vector2f posicion);


    void mover(const std::string& direccion);
    void actualizarSprite();

    // Métodos específicos de Ray
    void usarSuperColpedeLuz();
    void usarBaston();
};

#endif // RAY_H