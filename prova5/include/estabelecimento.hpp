#ifndef WSN_ESTABELECIMENTO_H
#define WSN_ESTABELECIMENTO_H

#include "produto.hpp"
#include "fornecedor.hpp"

#include <string>
#include <fstream>

class Estabelecimento{
    public:
    std::string listaDeProdutos;
    Estabelecimento(std::string listaDePordutos);
    static vector_supermercado<Produto> produtos;
    static vector_supermercado<Produto> caixa;
    static float valor_total;

    void atualizarEstoque();
    void atualizarCaixa(Produto p);
    void listar();
    Produto venda(size_t codigo, float saldo);
    void Caixa();
    void reabastecer(Fornecedor *f, std::string nome, int quantidade);
};

#endif 