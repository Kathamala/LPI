#include <iostream>
#include <string>
#include <vector>

#include "../include/cliente.hpp"
#include "../include/estabelecimento.hpp"
#include "../include/produto.hpp"
#include "../include/fornecedor.hpp"

 
int main(){

    Estabelecimento loja("estoque.csv");
    Fornecedor f;

    std::string opcao = "-1";
    int i = 0;

    std::vector<Cliente> c;
    Cliente cliente;
    c.push_back(cliente);

    while(opcao != "0"){
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Digite o número correspondente ao comando: " << std::endl;
        std::cout << "1 - Adicionar saldo do cliente " << std::endl;
        std::cout << "2 - Verificar os produtos da loja " << std::endl;
        std::cout << "3 - Ver conteúdo da sacola do cliente " << std::endl;
        std::cout << "4 - Realizar compra " << std::endl;
        std::cout << "5 - Ver tudo que foi vendido e o total ganho " << std::endl;        
        std::cout << "6 - Listar produtos do fornecedor " << std::endl; 
        std::cout << "7 - Reabastecer estoque " << std::endl; 
        std::cout << "0 - Sair " << std::endl;
        std::cout << "-------------------------------------------" << std::endl;

        std::cin >> opcao;

        if(opcao == "1"){
            std::string line;
            std::cout << "Digite o valor que será acrescentado: " << std::endl;
            std::cin.ignore();
            getline(std::cin, line);
            c[i].saldo += stof(line);
            std::cout<< "Crédito Adcionado! Saldo atual: " << c[i].saldo << std::endl;
        } else if(opcao == "2"){
            loja.listar();
        } else if(opcao == "3"){
            c[i].verSacola();
        } else if(opcao == "4"){
            std::cout << "Digite o nome do produto: " << std::endl;
            std::string nome;
            std::cin >> nome;
            c[i].compra(nome, loja);
        } else if(opcao == "5"){
            loja.Caixa();
        } else if(opcao == "6"){
            f.listarProdutos();
        } else if(opcao == "7"){
            std::string nome;
            std::string quantidade;
            std::cout << "Informe o nome do produto: " << std::endl;
            std::cin.ignore();
            getline(std::cin, nome);
            std::cout << "Informe a quantidade do produto: " << std::endl;
            getline(std::cin, quantidade);

            int q = stoi(quantidade);

            loja.reabastecer(&f, nome, q);

        } else if(opcao == "0"){
            std::cout << "Deseja inicializar um novo cliente (1- Sim / 2- Não): " << std::endl;
            std::cin >> opcao;
            if(opcao == "1"){
                opcao == "-1";
                i++;
                Cliente cliente;
                c.push_back(cliente);
            } else if(opcao == "2"){
                std::cout << "Programa finalizado! " << std::endl;
                return 0;
            }
        } else{
            std::cout << "Opção inválida! " << std::endl;
        };
    }

    return 0;
}