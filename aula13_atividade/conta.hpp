#ifndef CONTA
#define CONTA

#include <string>

class Conta{
    public:
    size_t numero;
    std::string titular;
    float saldo;

    void saca(float valor);
    void deposita(float valor);
    void transfere(float valor, Conta &conta2);
};

#endif