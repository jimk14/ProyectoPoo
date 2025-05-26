//
// Created by javiu on 24/05/2025.
//
#ifndef BASTON_H
#define BASTON_H

class Baston {
private:
    int carga;
    const int cargaMax = 100;

public:
    Baston();
    void recargar(int cantidad);
    void usarGolpe();
    void usarSuperGolpe();
    bool puedeSuperGolpe() const;
    int getCarga() const;
};

#endif