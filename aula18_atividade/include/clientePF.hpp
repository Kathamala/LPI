#ifndef CLIENTEPF
#define CLIENTEPF

#include <string>

#include "cliente.hpp"

using namespace std;

class clientePF : public cliente{
    public:
    string nome;
    int cpf;
    static int quantidadeClientes;

    clientePF();
    ~clientePF();
};

#endif
