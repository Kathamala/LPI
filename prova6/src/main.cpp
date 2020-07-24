#include <iostream>
#include <string>
#include <vector>

#include "../include/cliente.hpp"
#include "../include/estabelecimento.hpp"
#include "../include/produto.hpp"
#include "../include/fornecedor.hpp"

#include "../include/supermercado.hpp"
#include "../include/restaurante.hpp"

 
int main(){

    Supermercado loja("estoque.csv");
    Restaurante r("menu.csv");

    Fornecedor f;

    std::string opcao = "0";
    std::string opcaoEstabelecimento = "-1";
    int i = 0;

    std::vector<Cliente> c;
    Cliente cliente;
    c.push_back(cliente);

    while(opcaoEstabelecimento != "1" && opcaoEstabelecimento != "2"){
        std::cout << "Deseja abrir o Supermercado (1) ou o Restaurante (2):" << std::endl;
        std::cin >> opcaoEstabelecimento;

        try{
            if(opcaoEstabelecimento != "1" && opcaoEstabelecimento != "2"){
                throw(opcaoEstabelecimento);
            }
        } catch(std::string x){
            std::cout << "Tratador de erro chamado..." << std::endl;
            std::cout << x << " não é uma opção válida!" << std::endl;
        }
    }

    opcao = "-1";

    if(opcaoEstabelecimento == "1"){
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

            try{
                if(opcao != "1" && opcao != "2" && opcao != "3" && opcao != "4" && opcao != "5" && opcao != "6" && opcao != "7" && opcao != "0"){
                    throw(opcao);
                }

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

                    c[i].compra(nome, &loja);

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
                        std::cout << "Supermercado finalizado! " << std::endl;
                        break;
                    }
                }      

            } catch(std::string x){
                std::cout << "Tratador de erro chamado..." << std::endl;
                std::cout << x << " não é uma opção válida!" << std::endl;
            }

        }
    } else if(opcaoEstabelecimento == "2"){
        while(opcao != "0"){

                std::cout << "-------------------------------------------" << std::endl;
                std::cout << "Digite o número correspondente ao comando: " << std::endl;
                std::cout << "1 - Adicionar saldo do cliente " << std::endl;
                std::cout << "2 - Verificar cardápio " << std::endl;
                std::cout << "3 - Ver conteúdo da sacola do cliente " << std::endl;
                std::cout << "4 - Realizar compra " << std::endl;
                std::cout << "5 - Ver tudo que foi vendido e o total ganho " << std::endl;        
                std::cout << "0 - Sair " << std::endl;
                std::cout << "-------------------------------------------" << std::endl;

                std::cin >> opcao;

            try{
                if(opcao != "1" && opcao != "2" && opcao != "3" && opcao != "4" && opcao != "5" && opcao != "0"){
                    throw(opcao);
                }            

                if(opcao == "1"){
                    std::string line;
                    std::cout << "Digite o valor que será acrescentado: " << std::endl;
                    std::cin.ignore();
                    getline(std::cin, line);
                    c[i].saldo += stof(line);
                    std::cout<< "Crédito Adcionado! Saldo atual: " << c[i].saldo << std::endl;
                } else if(opcao == "2"){
                    r.listar();
                } else if(opcao == "3"){
                    c[i].verSacola();
                } else if(opcao == "4"){
                    std::cout << "Digite o nome do produto: " << std::endl;
                    std::string nome;
                    std::cin.ignore();
                    getline(std::cin, nome);

                    std::cout << "Digite a quantidade: " << std::endl;
                    int q;
                    std::cin >> q;

                    c[i].compra(nome, q, &r);

                } else if(opcao == "5"){
                    r.Caixa();
                } else if(opcao == "0"){
                    std::cout << "Deseja inicializar um novo cliente (1- Sim / 2- Não): " << std::endl;
                    std::cin >> opcao;
                    if(opcao == "1"){
                        opcao == "-1";
                        i++;
                        Cliente cliente;
                        c.push_back(cliente);
                    } else if(opcao == "2"){
                        std::cout << "Restaurante finalizado! " << std::endl;
                        break;
                    }
                }
            }
        catch(std::string x){
            std::cout << "Tratador de erro chamado..." << std::endl;
            std::cout << x << " não é uma opção válida!" << std::endl;
        }
    }
    }
    
    return 0;
}