#ifndef REYHONGO_H
#define REYHONGO_H

class ReyHongo {
private:
    int vida;
    int Esporas;
    int ControlMental;
    bool estaVivo;

public:
    ReyHongo();


    void liberarEsporas();
    void usarControlMental();


    void recibirDanio(int danio, bool esLuz);


    int getVida() const;
    bool vivo() const;
};

#endif