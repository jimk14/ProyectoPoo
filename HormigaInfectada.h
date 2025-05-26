#ifndef HORMIGAINFECTADA_H
#define HORMIGAINFECTADA_H

#include <SFML/Graphics.hpp>

class HormigaInfectada {
private:
    sf::Texture texturaViva;
    sf::Texture texturaAtaque;
    sf::Texture texturaMuerta;  
    sf::Sprite sprite;
    sf::Vector2f posicion;
    float velocidad;
    bool viva;
    int vida;

public:
    HormigaInfectada();
    void actualizar();
    void dibujar(sf::RenderWindow &ventana);
    void atacar();
    bool estaViva() const;
    void recibirDano(int cantidad);
    void mostrarBarraVida();
};

#endif
