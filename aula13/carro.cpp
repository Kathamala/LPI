#include "carro.hpp"

void Carro::acelera(int velocidade){
    this->velocidade += velocidade;
}
void Carro::freia(int velocidade){
    this->velocidade -= velocidade;
}