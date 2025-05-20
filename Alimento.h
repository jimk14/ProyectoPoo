#ifndef ALIMENTO_H
#define ALIMENTO_H

#include <string>
using namespace std;

class Alimento {
private:
    string alimento;
    int valorVida;

public:
    Alimento(const string &alimento, int valorVida);

    void usar();

    // Getters
    string getalimento() const;
    int getValorVida() const;

    // Setters
    void setalimento(const string& alimento);

    void setValorVida(int valor);

};

#endif //ALIMENTO_H
