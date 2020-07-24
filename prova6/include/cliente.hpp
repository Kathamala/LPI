#ifndef W5N_CLIENTE_H
#define WSN_CLIENTE_H

#include <string>

#include "produto.hpp"
#include "estabelecimento.hpp"

#include "supermercado.hpp"
#include "restaurante.hpp"

class Cliente{
    public:
    Cliente();
    static int numCliente;
    float saldo;
    vector_supermercado<Produto> sacola;

    void compra(std::string nome, Supermercado *estabelecimento);
    void compra(std::string nome, int q, Restaurante *estabelecimento);
    void verSacola();
    void registro(int opcaoEstabelecimento);
};

#endif 