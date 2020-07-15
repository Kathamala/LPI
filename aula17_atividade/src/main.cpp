#include <iostream>

#include "../include/conta.hpp"
#include "../include/fila.hpp"

int main(){

    cliente c1;
    c1.nome = "Cliente 1";
    cliente c2;
    c2.nome = "Cliente 2";
    clientePJ cPJ1;
    cPJ1.setRazaoSocial("ClientePJ 1");
    clientePJ cPJ2;
    cPJ2.setRazaoSocial("ClientePJ 2");

    fila<cliente> fila_cliente(3);
    fila<clientePJ> fila_clientePJ(3);

    fila_cliente.push(c1);
    fila_cliente.push(c2);
    fila_clientePJ.push(cPJ1);
    fila_clientePJ.push(cPJ2);

    std::cout << fila_cliente.isEmpty() << std::endl;
    std::cout << fila_clientePJ.isEmpty() << std::endl;

    std::cout << fila_cliente.front().nome << std::endl;
    std::cout << fila_cliente.back().nome << std::endl;
    std::cout << fila_clientePJ.front().getRazaoSocial() << std::endl;
    std::cout << fila_clientePJ.back().getRazaoSocial() << std::endl;

    fila_cliente.pop();
    fila_clientePJ.pop();

    std::cout << fila_cliente.sizeOf() << std::endl;
    std::cout << fila_clientePJ.sizeOf() << std::endl;

    return 0;
}