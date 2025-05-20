#include "Alimento.h"
using namespace std;

Alimento::Alimento(const string& alimento, int valorVida) {
    this->alimento = alimento;
    this -> valorVida = valorVida;
}

void Alimento::usar() {

}


int Alimento::getValorVida() const {
    return valorVida;
}


void Alimento::setValorVida(int valor) {
    this ->valorVida = valor;
}