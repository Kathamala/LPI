#include "conta.hpp"

void Conta::saca(float valor){
    saldo -= valor;
}
void Conta::deposita(float valor){
    saldo += valor;
}
void Conta::transfere(float valor, Conta &conta2){
    conta2.saldo += valor;
    saldo -= valor;
}