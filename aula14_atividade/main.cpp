#include <iostream>
#include "conta.hpp"

using namespace std;

int main(){
    Agencia a;
    a.nome = "BdB";
    a.numeroDaAgencia = 1385135861305;
    
    Agencia a2;
    a2.nome = "Santander";
    a2.numeroDaAgencia = 654654163546;

    Conta c1;
    c1.numero = 91826441;
    c1.saldo = 100;
    c1.agencia = a;

    Cliente cl1;
    cl1.nome = "ADELBERT STEINER";
    cl1.cpf = "000.000.000-00";
    c1.titular = cl1;

    Conta c2;
    c2.numero = 98136548;
    c2.saldo = 200;
    c2.agencia = a2;

    Cliente cl_2;
    cl_2.nome = "HENRY ADAMS";
    cl_2.cpf = "111.111.111-11";
    c2.titular = cl_2;

    c1.deposita(4.50f);
    c2.saca(55.42f);

    std::cout << "- Conta 1: " << std::endl;
    std::cout << "Numero: " << c1.numero << std::endl;
    std::cout << "Saldo: " << c1.saldo << std::endl;
    std::cout << "Titular: " << c1.titular.nome << std::endl;
    std::cout << "Agencia: " << c1.agencia.nome << std::endl;

    std::cout << "- Conta 2: " << std::endl;
    std::cout << "Numero: " << c2.numero << std::endl;
    std::cout << "Saldo: " << c2.saldo << std::endl;
    std::cout << "Titular: " << c2.titular.nome << std::endl;
    std::cout << "Agencia: " << c2.agencia.nome << std::endl;

    std::cout << "----------------------------" << std::endl;
    c1.transfere(50, c2);

    std::cout << "- Conta 1: " << std::endl;
    std::cout << "Saldo: " << c1.saldo << std::endl;
    std::cout << "- Conta 2: " << std::endl;
    std::cout << "Saldo: " << c2.saldo << std::endl;
    return 0;
} 