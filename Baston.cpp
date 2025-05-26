#include "Baston.h"
#include <iostream>
#include <stdexcept>

Baston::Baston() {
    carga = 0;
}

void Baston::recargar(int cantidad) {
    carga += cantidad;
    if (carga > cargaMax) carga = cargaMax;
}

void Baston::usarGolpe() {
    if (carga < 10) std::cout << "No hay suficiente carga para golpear\n";
    else carga -= 10;
}

void Baston::usarSuperGolpe() {
    if (carga < cargaMax) throw std::runtime_error("Carga insuficiente para super golpe");
    std::cout << "¡Super golpe de luz activado!\n";
    carga = 0;
}

bool Baston::puedeSuperGolpe() const {
    return carga >= cargaMax;
}

int Baston::getCarga() const {
    return carga;
}
