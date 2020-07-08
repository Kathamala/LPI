#include <iostream>
#include "carro.hpp"

using namespace std;

int main(){
    Carro a;
    std::cout << "Quantidade de Carros: " << a.quantidadeCarros << std::endl;
    Carro b;
    Carro c;
    std::cout << "Quantidade de Carros: " << c.quantidadeCarros << std::endl;

    return 0;
}