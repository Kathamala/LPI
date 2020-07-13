#ifndef WSN_PRODUTO_H 
#define WSN_PRODUTO_H

#include <string>

class Produto{
    public:
    Produto(size_t codigo, std::string nome, std::string unidadeMedida, float preco, int quantidadeEstoque);

    size_t codigo;
    std::string nome;
    std::string unidadeMedida;
    float preco;
    int quantidadeEstoque;
    int quantidadeVendida;
};

#endif