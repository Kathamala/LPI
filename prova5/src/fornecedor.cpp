#include "../include/fornecedor.hpp"
#include <fstream>

Fornecedor::Fornecedor(){
    std::ifstream read_file("fornecedor.csv");

    std::string line;
    getline(read_file, line); //discard
    std::string nome;
    int quantidade;
    while(!read_file.eof()){
        //Nome
        getline(read_file, line, ',');
        nome = line;
        //Quantidade
        getline(read_file, line);
        quantidade = stoi(line);       

        Produto p(0, nome, "0", 0, quantidade);
        this->produtos_fornecedor.push(p); 
    }
}
void Fornecedor::listarProdutos(){
    for(int i=0; i < this->produtos_fornecedor.sizeOf(); i++){
        std::cout << this->produtos_fornecedor.at(i)->nome << ": " << this->produtos_fornecedor.at(i)->quantidadeEstoque << std::endl;
    }
}
bool Fornecedor::repassarProdutos(std::string nome, int quantidade){
    for(int i = 0; i < this->produtos_fornecedor.sizeOf(); ++i){
        if(this->produtos_fornecedor.at(i)->nome == nome){
            if(this->produtos_fornecedor.at(i)->quantidadeEstoque >= quantidade){
                produtos_fornecedor.at(i)->quantidadeEstoque -= quantidade;
                atualizarFornecedor();
                std::cout << "- Estoque atualizado!" << std::endl;
                return true;
            }
            std::cout << "- Quantidade insufuciente no fornecedor" << std::endl;
            return false;
        }
    }

    std::cout << "- Produto não encontrado no fornecedor" << std::endl;
    return false;
}

void Fornecedor::atualizarFornecedor(){
    std::ofstream write_file("fornecedor.csv");

    write_file << "PRODUTO,QUANTIDADE" << std::endl;
    int j = 0;
    for(int i = 0; i < this->produtos_fornecedor.sizeOf(); ++i){
        j++;
        write_file << this->produtos_fornecedor.at(i)->nome << "," << this->produtos_fornecedor.at(i)->quantidadeEstoque;
        if(j != produtos_fornecedor.sizeOf()){
            write_file << std::endl;
        }
    }
}