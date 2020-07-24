#ifndef WSN_SUPERMERCADO_H 
#define WSN_SUPERMERCADO_H

#include "estabelecimento.hpp"
#include <string>

class Supermercado : public Estabelecimento{
    public:
    Supermercado(std::string nomeArquivo);
    void atualizarEstoque();
    void listar();
    Produto venda(size_t codigo, float saldo);
    void reabastecer(Fornecedor *f, std::string nome, int quantidade);
    void atualizarCaixa(Produto p);
};

#endif