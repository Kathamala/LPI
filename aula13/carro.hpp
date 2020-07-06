#ifndef CARRO
#define CARRO

#include <string>

class Carro{
    public: //atributos podem ser acessado fora da classe
    std::string tipo;
    std::string cor;
    int numPortas;
    int velocidade;

    void acelera(int velocidade);
    void freia(int velocidade);
};

#endif