#include "../include/estabelecimento.hpp" 

#include <iostream>
#include <iomanip>

vector_supermercado<Produto> Estabelecimento::caixa;

float Estabelecimento::valor_total;

void Estabelecimento::Caixa(){
    std::cout << "PRODUTO,PREÇO,QUANTIDADE" << std::endl;
    char aspa = '"';

    for(auto i = caixa.begin(); i != caixa.end(); i++){
        std::cout << i->nome << "," << aspa << "R$ " << std::fixed << std::setprecision(2) << i->preco << aspa << "," << i->quantidadeVendida << std::endl;
    }

    std::cout << "TOTAL: R$" << valor_total << std::endl;
    return;
}
