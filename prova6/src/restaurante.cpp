#include "../include/restaurante.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>

Restaurante::Restaurante(std::string nomeArquivo){
    this->listaDeProdutos = nomeArquivo;
    this->listaDeCaixa = "caixa_restaurante.csv";

    std::ifstream read_file(nomeArquivo);

    if(read_file.fail()){
        std::cout << "Arquivo de estoque não encontrado" << std::endl;
        return;   
    } 

    std::string line;
    getline(read_file, line);

    std::string nome;
    float preco;

    while(!read_file.eof()){
        //Nome
        getline(read_file, line, ',');
        nome = line;
        //Preco
        getline(read_file, line, ' ');
        getline(read_file, line);
        preco = stof(line); 

        Produto p(0, nome, "Vazio", preco, -1);
        produtos.push(p);
    }    
}

void Restaurante::listar(){
    std::cout << "ITEM,PREÇO" << std::endl;

    for(auto i = produtos.begin(); i != produtos.end(); i++){
        std::cout << i->nome << "," << "R$ " << std::fixed << std::setprecision(2) << i->preco << std::endl;
    }

    return;
}

Produto Restaurante::venda(std::string nome, int q, float saldo){
    Produto vazio(0, "Vazio", "Vazio", 0, 0);
    
    for(auto i = produtos.begin(); i != produtos.end(); i++){
        if(i->nome == nome){
            if(saldo >= (i->preco)*q){
                std::cout << "Venda efetuada com sucesso!" << std::endl;
                atualizarCaixa(*i, q);
                return *i;
            }
            std::cout << "Desculpe, mas você não possui saldo suficiente para efetuar a compra! " << std::endl;
            return vazio;
        }
    }
    return vazio;
}

void Restaurante::atualizarCaixa(Produto p, int q){
    std::ofstream write_file(this->listaDeCaixa);

    for(auto i = caixa.begin(); i != caixa.end(); i++){
        if(i->nome == p.nome){
            i->quantidadeVendida += q;

            char aspa = '"';

            write_file << "NOME,PREÇO,QUANTIDADE_VENDIDA" << std::endl;
            valor_total = 0; 

            for(auto i = caixa.begin(); i != caixa.end(); i++){
                write_file << i->nome << "," << aspa << "R$ " << std::fixed << std::setprecision(2) << i->preco << aspa << "," << i->quantidadeVendida << std::endl;
                valor_total += i->preco * i->quantidadeVendida;
            }            

            write_file << "TOTAL: R$" << valor_total << std::endl;
            return;
        }
    }    

    p.quantidadeVendida+=q;
    caixa.push(p);

    char aspa = '"';

    write_file << "COD,NOME,PREÇO,QUANTIDADE_VENDIDA" << std::endl;
    valor_total = 0;

    for(auto i = caixa.begin(); i != caixa.end(); i++){
        write_file << i->codigo << "," << i->nome << "," << aspa << "R$ " << std::fixed << std::setprecision(2) << i->preco << aspa << "," << i->quantidadeVendida << std::endl;
        valor_total += i->preco * i->quantidadeVendida;
    }

    write_file << "TOTAL: R$" << valor_total << std::endl;
    return;
}