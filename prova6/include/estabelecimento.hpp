#ifndef WSN_ESTABELECIMENTO_H
#define WSN_ESTABELECIMENTO_H

#include "produto.hpp"
#include "fornecedor.hpp"

#include <string>
#include <fstream>

class Estabelecimento{
    public:
    std::string listaDeProdutos;
    std::string listaDeCaixa;
    vector_supermercado<Produto> produtos;
    static vector_supermercado<Produto> caixa;
    static float valor_total;

    void Caixa();
};

#endif  