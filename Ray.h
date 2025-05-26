#ifndef RAY_H
#define RAY_H

#include "Personaje.h"
#include "Baston.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>

class Ray : public Personaje {
private:
    Baston baston;
    sf::Texture texturaReposo;
    sf::Texture texturaSalto;
    std::vector<sf::Texture> texturasCaminar;
    sf::Texture texturaGolpe;
    sf::Texture texturaLuz;
    std::map<std::string, int> inventario;

    int frame, frameCounter, frameDelay;
    int accionFrameCounter, accionFrameDelay;
    bool enAccionEspecial;
    bool mirandoDerecha;

    int vidaMaxima = 200;
    int vidaActual = 200;

    float energiaLuz;
    float energiaMaxima = 100.f;
    float energiaRecargaVelocidad = 20.f; // por segundo

public:
    Ray();

    void manejarEntrada() override;
    void actualizar() override;
    void dibujar(sf::RenderWindow& window) override;

    void recargarLuz(int cantidad);
    void recibirDanyo(int cantidad);
    int getVida() const { return vidaActual; }
    int getVidaMaxima() const { return vidaMaxima; }
    sf::Vector2f getPosicion() const;
    sf::Texture texturaMuerte;
    bool estaMuerto() const { return vidaActual <= 0; }
    void agregarAlimento(const std::string& item);
    void mostrarInventario() const;
};

#endif
