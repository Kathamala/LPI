#include <iostream>
#include "conta.hpp"

int main(){

    Conta c1;
    c1.numero = 91826441;
    c1.saldo = 100;
    c1.titular = "ADELBERT STEINER";
    Conta c2;
    c2.numero = 98136548;
    c2.saldo = 200;
    c2.titular = "EDGAR FIGARO";

    c1.deposita(4.50f);
    c2.saca(55.42f);

    std::cout << "- Conta 1: " << std::endl;
    std::cout << "Numero: " << c1.numero << std::endl;
    std::cout << "Saldo: " << c1.saldo << std::endl;
    std::cout << "Titular: " << c1.titular << std::endl;

    std::cout << "- Conta 2: " << std::endl;
    std::cout << "Numero: " << c2.numero << std::endl;
    std::cout << "Saldo: " << c2.saldo << std::endl;
    std::cout << "Titular: " << c2.titular << std::endl;

    std::cout << "----------------------------" << std::endl;
    c1.transfere(50, c2);

    std::cout << "- Conta 1: " << std::endl;
    std::cout << "Saldo: " << c1.saldo << std::endl;
    std::cout << "- Conta 2: " << std::endl;
    std::cout << "Saldo: " << c2.saldo << std::endl;
    return 0;
}