#ifndef W5N_CLIENTE_H
#define WSN_CLIENTE_H

#include <string>

#include "produto.hpp"
#include "estabelecimento.hpp"

class Cliente{
    public:
    Cliente();
    static int numCliente;
    float saldo;
    vector_supermercado<Produto> sacola;

    void compra(std::string nome, Estabelecimento estabelecimento);
    void verSacola();
    void registro();
};

#endif 