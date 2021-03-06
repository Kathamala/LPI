#ifndef CONTA
#define CONTA

#include <string>
#include "cliente.hpp"
#include "clientePF.hpp"
#include "clientePJ.hpp"

using namespace std;

class conta{
    public:
    int numero;
    cliente titular;
    double saldo;
    static int quantidadeContas;

    conta(cliente titular);
    conta();
    ~conta();

    void saca(double quantidade);
    void deposita(double quantidade);
    void transfere(conta &c, double quantidade);

};

#endif