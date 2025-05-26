#ifndef REYHONGOGRAFICO_H
#define REYHONGOGRAFICO_H

#include <SFML/Graphics.hpp>
#include <vector>

class ReyHongoGrafico {
private:
    std::vector<sf::Texture> texturasHongo;
    sf::Sprite hongoSprite;
    sf::Vector2f posicion;
    int estadoActual;

    // Barra de vida
    sf::RectangleShape barraVidaFondo;
    sf::RectangleShape barraVida;
    int vidaMaxima;

    void cargarTexturas();

public:
    ReyHongoGrafico(sf::Vector2f posicionInicial);

    void atacar();                     
    void recibirDanio();               
    void actualizarVida(int vidaActual);  
    void actualizarSprite();           
    void dibujar(sf::RenderWindow& ventana);
};

#endif