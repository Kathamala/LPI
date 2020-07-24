#ifndef WSN_RESTAURANTE_H 
#define WSN_RESTAURANTE_H

#include "estabelecimento.hpp"

class Restaurante : public Estabelecimento{
    public:
    Restaurante(std::string nomeArquivo);
    void listar();
    Produto venda(std::string nome, int q, float saldo);
    void atualizarCaixa(Produto p, int q);
};

#endif