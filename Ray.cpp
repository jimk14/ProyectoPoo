#include "Ray.h"

Ray::Ray(int vitalidad, sf::Vector2f posicion)
    : Hormiga(100, 20, vitalidad, posicion) {
    cargarTexturaRay();
    actualizarSprite();
}

void Ray::cargarTexturaRay() {
        if (!HormigaNormal.loadFromFile("ray.png")) {
            return;
        }
        HormigaSprite.setTexture(HormigaNormal);
        actualizarsprite();
    }


void Ray::mover(const std::string& direccion) {
    float velocidad = 5.0;

    if (direccion == "izquierda") {
        posicion.x -= velocidad;
        HormigaSprite.setScale({-1.f, 1.f});
    }
    else if (direccion == "derecha") {
        posicion.x += velocidad;
        HormigaSprite.setScale({1, 1});
    }
    else if (direccion == "arriba") {
        posicion.y -= velocidad;
    }
    else if (direccion == "abajo") {
        posicion.y += velocidad;
    }

    actualizarSprite();
}

void Ray::actualizarSprite() {
    HormigaSprite.setPosition(posicion);
}


void usarSuperColpedeLuz() {

}

void usarBaston() {

}