#include "conta.hpp"

void Conta::saca(double valor){
    saldo -= valor;
}
void Conta::deposita(double valor){
    saldo += valor;
}
void Conta::transfere(double valor, Conta &c){
    c.saldo += valor;
    saldo -= valor;
}