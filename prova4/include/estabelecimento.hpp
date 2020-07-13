#ifndef WSN_ESTABELECIMENTO_H
#define WSN_ESTABELECIMENTO_H

#include "produto.hpp"

#include <list>
#include <string>
#include <fstream>

class Estabelecimento{
    public:
    std::string listaDeProdutos;
    Estabelecimento(std::string listaDePordutos);
    static std::list<Produto> produtos;
    static std::list<Produto> caixa;
    static float valor_total;

    void atualizarEstoque();
    void atualizarCaixa(Produto p);
    void listar();
    Produto venda(size_t codigo, float saldo);
    void Caixa();
};

#endif 