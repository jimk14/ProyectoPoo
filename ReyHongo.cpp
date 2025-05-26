#include "ReyHongo.h"

ReyHongo::ReyHongo() {
    vida = 100;
    Esporas = 10;
    ControlMental = 25;
    estaVivo = true;
}

void ReyHongo::liberarEsporas() {

}

void ReyHongo::usarControlMental() {

}

void ReyHongo::recibirDanio(int danio, bool esLuz) {
    if (esLuz) {
        danio *= 2;
    }
    vida -= danio;
    if (vida <= 0) {
        vida = 0;
        estaVivo = false;
    }
}

int ReyHongo::getVida() const {
    return vida;
}

bool ReyHongo::vivo() const {
    return estaVivo;
}