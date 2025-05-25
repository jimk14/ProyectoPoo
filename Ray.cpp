#include "Ray.h"

Ray::Ray(int vitalidad, sf::Vector2f posicion)
    : Hormiga(100, 20, vitalidad, posicion) {
    cargarTexturaRay();
    actualizarSprite();
}



void Ray::cargarTexturaRay() {
    sf::Texture texture;
    if (!texture.loadFromFile("ray.png")) {
        return;
    }
    sf::RectangleShape rectangle({100,150});
    rectangle.setTexture(&texture);
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(sf::Vector2f(0, 900 - rectangle.getSize().y));
        HormigaSprite.setTexture(texture);
        actualizarsprite();
    }


void Ray::mover(const std::string& direccion) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        HormigaSprite.move(sf::Vector2f(0, -velocity));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        HormigaSprite.move(sf::Vector2f(0, velocity));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        HormigaSprite.move(sf::Vector2f(-velocity, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        HormigaSprite.move(sf::Vector2f(velocity, 0));
    }
}
void Ray::actualizarSprite() {
    HormigaSprite.setPosition(posicion);
}

void Ray::dibujar(sf::RenderWindow& window) {
    window.draw(HormigaSprite);
}
void usarSuperColpedeLuz() {

}

void usarBaston() {

}
