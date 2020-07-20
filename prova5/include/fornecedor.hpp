#ifndef WSN_FORNECEDOR_H
#define WSN_FORNECEDOR_H

#include "produto.hpp"
#include "vector_supermercado.hpp"

#include <string>

class Fornecedor{
    public:
    vector_supermercado<Produto> produtos_fornecedor;   

    Fornecedor();
    void listarProdutos();
    bool repassarProdutos(std::string nome, int quantidade);
    void atualizarFornecedor();
};

#endif