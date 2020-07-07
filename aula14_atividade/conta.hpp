#include "cliente.hpp"
#include "agencia.hpp"

class Conta{
    public:
    int numero;
    Cliente titular;
    Agencia agencia;
    double saldo;

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta &c);
}; 