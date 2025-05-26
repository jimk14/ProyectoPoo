#include "Ray.h"
#include <iostream>

Ray::Ray() {
    if (!texturaReposo.loadFromFile("rayy.png")) std::cerr << "no se pudo cargar rayy.png\n";

    texturasCaminar.resize(2);
    if (!texturasCaminar[0].loadFromFile("walk1.png")) std::cerr << "no se pudo cargar walk1.png\n";
    if (!texturasCaminar[1].loadFromFile("walk2.png")) std::cerr << "no se pudo cargar walk2.png\n";
    if (!texturaGolpe.loadFromFile("golpe.png")) std::cerr << "no se pudo cargar golpe.png\n";
    if (!texturaLuz.loadFromFile("luz.png")) std::cerr << "no se pudo cargar luz.png\n";
    if (!texturaSalto.loadFromFile("salto.png")) std::cerr << "no se pudo cargar salto.png\n";
    if (!texturaMuerte.loadFromFile("muerte.png")) std::cerr << "no se pudo cargar muerte.png\n";


    cuerpo.setTexture(&texturaReposo);
    auto size = cuerpo.getTexture()->getSize();
    cuerpo.setSize({static_cast<float>(size.x), static_cast<float>(size.y)});
    cuerpo.setOrigin({cuerpo.getSize().x / 2.f, 0});

    frame = 0;
    frameCounter = 0;
    frameDelay = 10;

    accionFrameCounter = 0;
    accionFrameDelay = 15;
    enAccionEspecial = false;

    mirandoDerecha = true;
    energiaLuz = energiaMaxima; // inicia cargada
}

void Ray::manejarEntrada() {
    if (enAccionEspecial) return;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        if (cuerpo.getPosition().x - cuerpo.getOrigin().x > 0) {
            cuerpo.move({-velocidad, 0});
        }
        cuerpo.setScale({1.f, 1.f});
        cuerpo.setOrigin({cuerpo.getSize().x, 0});
        mirandoDerecha = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        cuerpo.move({velocidad, 0});
        cuerpo.setScale({-1.f, 1.f});
        cuerpo.setOrigin({0, 0});
        mirandoDerecha = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        if (enSuelo) {
            velocidadVertical = salto;
            enSuelo = false;
            cuerpo.setTexture(&texturaSalto);
            auto size = cuerpo.getTexture()->getSize();
            cuerpo.setSize({static_cast<float>(size.x), static_cast<float>(size.y)});
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        cuerpo.setTexture(&texturaGolpe);
        enAccionEspecial = true;
        accionFrameCounter = 0;
        baston.usarGolpe();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X)) {
        if (energiaLuz >= energiaMaxima) {
            energiaLuz = 0; // se gasta al usar
            cuerpo.setTexture(&texturaLuz);
            enAccionEspecial = true;
            accionFrameCounter = 0;
            try {
                baston.usarSuperGolpe();
            } catch (std::exception& e) {
                std::cout << e.what() << '\n';
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)) {
        vidaActual += 20;
        if (vidaActual > vidaMaxima) vidaActual = vidaMaxima;
    }
}

void Ray::actualizar() {
    Personaje::actualizar();

    if (estaMuerto()) {
        cuerpo.setTexture(&texturaMuerte);
        auto size = cuerpo.getTexture()->getSize();
        cuerpo.setSize({static_cast<float>(size.x), static_cast<float>(size.y)});
        return;
    }

    if (enAccionEspecial) {
        accionFrameCounter++;
        if (accionFrameCounter >= accionFrameDelay) {
            cuerpo.setTexture(&texturaReposo);
            auto size = cuerpo.getTexture()->getSize();
            cuerpo.setSize({static_cast<float>(size.x), static_cast<float>(size.y)});
            enAccionEspecial = false;
        }
        return;
    }

    if (!enSuelo && cuerpo.getTexture() != &texturaSalto) {
        cuerpo.setTexture(&texturaSalto);
        auto size = cuerpo.getTexture()->getSize();
        cuerpo.setSize({static_cast<float>(size.x), static_cast<float>(size.y)});
        return;
    }

    if (enSuelo && cuerpo.getTexture() == &texturaSalto) {
        cuerpo.setTexture(&texturaReposo);
        auto size = cuerpo.getTexture()->getSize();
        cuerpo.setSize({static_cast<float>(size.x), static_cast<float>(size.y)});
    }

    bool caminando = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    if (caminando) {
        frameCounter++;
        if (frameCounter >= frameDelay) {
            frame = (frame + 1) % 2;
            cuerpo.setTexture(&texturasCaminar[frame]);
            auto size = cuerpo.getTexture()->getSize();
            cuerpo.setSize({static_cast<float>(size.x), static_cast<float>(size.y)});
            frameCounter = 0;
        }

        // Solo recarga cuando camina
        if (energiaLuz < energiaMaxima) {
            energiaLuz += energiaRecargaVelocidad * (1.f / 60.f); // asumiendo 60 FPS
            if (energiaLuz > energiaMaxima) energiaLuz = energiaMaxima;
        }
    } else if (enSuelo) {
        cuerpo.setTexture(&texturaReposo);
        auto size = cuerpo.getTexture()->getSize();
        cuerpo.setSize({static_cast<float>(size.x), static_cast<float>(size.y)});
    }
}

void Ray::dibujar(sf::RenderWindow& window) {
    Personaje::dibujar(window);
    sf::Vector2f posicion = cuerpo.getPosition();

    // Vida
    float anchoBarra = 65.f, altoBarra = 15.f, offsetY = 15.f;
    sf::Vector2f posVida(posicion.x - anchoBarra / 2.f, posicion.y - offsetY);
    sf::RectangleShape fondoVida({anchoBarra, altoBarra});
    fondoVida.setFillColor(sf::Color::Red);
    fondoVida.setPosition(posVida);
    float porcentajeVida = static_cast<float>(vidaActual) / vidaMaxima;
    sf::RectangleShape barraVida({anchoBarra * porcentajeVida, altoBarra});
    barraVida.setFillColor(sf::Color::Green);
    barraVida.setPosition(posVida);

    // Energía
    float anchoEnergia = 65.f, altoEnergia = 10.f, offsetEnergia = 35.f;
    sf::Vector2f posEnergia(posicion.x - anchoEnergia / 2.f, posicion.y - offsetEnergia);
    sf::RectangleShape fondoEnergia({anchoEnergia, altoEnergia});
    fondoEnergia.setFillColor(sf::Color(50, 50, 50));  // gris oscuro
    fondoEnergia.setPosition(posEnergia);
    float porcentajeEnergia = energiaLuz / energiaMaxima;
    sf::RectangleShape barraEnergia({anchoEnergia * porcentajeEnergia, altoEnergia});
    barraEnergia.setFillColor(sf::Color::Cyan);
    barraEnergia.setPosition(posEnergia);

    window.draw(fondoVida);
    window.draw(barraVida);
    window.draw(fondoEnergia);
    window.draw(barraEnergia);
}
void Ray::recargarLuz(int cantidad) {
    baston.recargar(cantidad);
}

void Ray::recibirDanyo(int cantidad) {
    vidaActual -= cantidad;
    if (vidaActual < 0) vidaActual = 0;
}

sf::Vector2f Ray::getPosicion() const {
    return cuerpo.getPosition();
}

void Ray::agregarAlimento(const std::string& item) {
    inventario[item]++;
    std::cout << "Se ha agregado '" << item << "' al inventario.\n";
}

void Ray::mostrarInventario() const {
    std::cout << "Inventario de Ray:\n";
    for (const auto& par : inventario) {
        std::cout << "- " << par.first << ": " << par.second << "\n";
    }
}
