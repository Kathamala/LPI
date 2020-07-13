#include "../include/produto.hpp"

Produto::Produto(size_t codigo, std::string nome, std::string unidadeMedida, float preco, int quantidadeEstoque){
    this->codigo = codigo;
    this->nome = nome;
    this->unidadeMedida = unidadeMedida;
    this->preco = preco;
    this->quantidadeEstoque = quantidadeEstoque;
    this->quantidadeVendida = 0;
}; 