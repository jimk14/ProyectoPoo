#include "HormigaNormal.h"
#include <iostream>
#include <tgmath.h>

HormigaNormal::HormigaNormal(int energia, int ataque, int vitalidad, sf::Vector2f posicion)
    : Hormiga(energia, ataque, vitalidad, posicion)
{
    cargartextura("Hormiganormal.png");
}

void HormigaNormal::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(HormigaSprite);  // Usa el sprite heredado
}


void HormigaNormal::interactuar(Ray& ray) {
    if (!yaInteractuo) {
        ray.agregarAlimento("Fruta");
        std::cout << "HormigaNormal: ¡Toma esta fruta como ayuda!\n";
        yaInteractuo = true;  // Evita que dé múltiples veces
    }
}
