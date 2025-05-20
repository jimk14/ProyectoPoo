#ifndef HORMIGA_H
#define HORMIGA_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Hormiga {
protected:
    int energia;
    int ataque;
    int vitalidad;
    int cambio{};
    sf::Vector2f posicion;
    sf::Texture HormigaNormal;
    sf::Sprite HormigaSprite;

public:
    Hormiga(int energia, int ataque, int vitalidad, sf::Vector2f posicion);
    virtual ~Hormiga();

    void cargartextura(const string&);

    void actualizarsprite ();

    // Getters
    virtual int getEnergia() const;
    virtual int getAtaque() const;
    virtual  int getVitalidad() const;
    sf::Vector2f getPosicion() const;
    const sf::Sprite& getSprite() const;

    // Setters
    void setEnergia(int energia);
    void setAtaque(int ataque);
    void setVitalidad(int vitalidad);
    void setPosicion(sf::Vector2f posicion);

};
#endif // HORMIGA_H
