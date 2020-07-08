#include <iostream>
#include "conta.hpp"

using namespace std;

int main(){
    cliente cl;
    conta a;
    std::cout << "Quantidade de clientes: " << cl.quantidadeClientes << std::endl;
    std::cout << "Quantidade de contas: " << a.quantidadeContas << std::endl;

    conta b;
    cliente cl2;
    std::cout << "Quantidade de clientes: " << cl.quantidadeClientes << std::endl;
    std::cout << "Quantidade de contas: " << a.quantidadeContas << std::endl;

    return 0;
}
