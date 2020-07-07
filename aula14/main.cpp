#include <iostream>
#include "conta.hpp"
#include "cliente.hpp"

int main(){
    Conta c;
    Cliente cl;


    cl.nome = "Jose";
    cl.cpf = "000.000.000-00";

    c.titular = cl;

    return 0;
}