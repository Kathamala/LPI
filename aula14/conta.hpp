#include "cliente.hpp"

class Conta{
    public:
    int numero;
    Cliente titular; //-> Composição ou Agregação
    double saldo;

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta &c);
};