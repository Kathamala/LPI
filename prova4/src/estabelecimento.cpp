#include "../include/estabelecimento.hpp" 

#include <iostream>
#include <iomanip>

std::list<Produto> Estabelecimento::produtos;
std::list<Produto> Estabelecimento::caixa;
float Estabelecimento::valor_total;

Estabelecimento::Estabelecimento(std::string listaDeProdutos){
    this->listaDeProdutos = listaDeProdutos;

    std::ifstream read_file(listaDeProdutos);

    if(read_file.fail()){
        std::cout << "Arquivo de estoque não encontrado" << std::endl;
        return;
    }

    std::string line;
    getline(read_file, line);

    size_t codigo;
    std::string nome;
    std::string unidadeMedida;
    float preco;
    int quantidadeEstoque;

    while(!read_file.eof()){
        //Codigo
        getline(read_file, line, ',');
        codigo = stoi(line);
        //Nome
        getline(read_file, line, ',');
        nome = line;
        //Unidade
        getline(read_file, line, ',');
        unidadeMedida = line;

        //Preco
        getline(read_file, line, ' ');
        getline(read_file, line, '"');
        preco = stof(line);
        getline(read_file, line, ',');

        //Estoque
        getline(read_file, line);
        quantidadeEstoque = stoi(line);        

        Produto p(codigo, nome, unidadeMedida, preco, quantidadeEstoque);
        produtos.push_back(p);
    }
}

void Estabelecimento::atualizarEstoque(){
    std::ofstream write_file(this->listaDeProdutos);

    write_file << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;

    char aspa = '"';
    int j = 0;

    for(auto i = produtos.begin(); i != produtos.end(); i++){
        j++;
        write_file << i->codigo << "," << i->nome << "," << i->unidadeMedida << "," << aspa << "R$ " << std::fixed << std::setprecision(2) << i->preco << aspa << "," << i->quantidadeEstoque;
        
        if(j != produtos.size()){
            write_file << std::endl;
        }
    }
    return;
}

void Estabelecimento::atualizarCaixa(Produto p){
    std::ofstream write_file("caixa.csv");

    for(auto i = caixa.begin(); i != caixa.end(); i++){
        if(i->codigo == p.codigo){
            i->quantidadeVendida++;

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
    }    

    p.quantidadeVendida++;
    caixa.push_back(p);

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

void Estabelecimento::listar(){
    std::cout << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
    char aspa = '"';

    for(auto i = produtos.begin(); i != produtos.end(); i++){
        std::cout << i->codigo << "," << i->nome << "," << i->unidadeMedida << "," << aspa << "R$ " << std::fixed << std::setprecision(2) << i->preco << aspa << "," << i->quantidadeEstoque << std::endl;
    }

    return;
}

Produto Estabelecimento::venda(size_t codigo, float saldo){
    Produto vazio(0, "Vazio", "Vazio", 0, 0);
    
    for(auto i = produtos.begin(); i != produtos.end(); i++){
        if(i->codigo == codigo){
            if(i->quantidadeEstoque > 0){
                if(saldo >= i->preco){
                    i->quantidadeEstoque -= 1;
                    std::cout << "Venda efetuada com sucesso!" << std::endl;
                    atualizarCaixa(*i);
                    atualizarEstoque();
                    return *i;
                }
                std::cout << "Desculpe, mas você não possui saldo suficiente para efetuar a compra! " << std::endl;
                return vazio;
            }
            std::cout << "Desculpe, mas esse produto está esgotado! " << std::endl;
            return vazio;
        }
    }
    return vazio;
}

void Estabelecimento::Caixa(){
    std::cout << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
    char aspa = '"';

    for(auto i = caixa.begin(); i != caixa.end(); i++){
        std::cout << i->codigo << "," << i->nome << "," << i->unidadeMedida << "," << aspa << "R$ " << std::fixed << std::setprecision(2) << i->preco << aspa << "," << i->quantidadeVendida << std::endl;
    }

    std::cout << "TOTAL: R$" << valor_total << std::endl;
    return;
}