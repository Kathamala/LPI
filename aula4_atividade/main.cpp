#include <iostream>
#include <fstream>
#include <string>
//Atividade: Listar todas as mensagens escritas com add usando um novo comando "list"
int main(int argc, char* argv[]){
    std::ofstream arquivo_saida("file.txt", std::ios::app);
    std::ifstream arquivo_entrada("file.txt");
    std::string mensagem;
    std::string comando;

    //verificar se arquivo foi aberto
    if(!arquivo_saida.is_open()){
        std::cerr << "O arquivo não pode ser criado" << std::endl; //cerr imprime como um erro
        return -1;
    }

    //./prog
    if(argc == 1){
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        std::cout << "Uso: " << argv[0] << " list" << std::endl;
        return -1;
    }
    
    //Verificar se começa com add
    comando = argv[1];
    if(comando != "add" && comando != "list"){
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        std::cout << "Uso: " << argv[0] << " list" << std::endl;
        return -1;
    }

    //./prog add mensagem
    if(argc > 2 && comando == "add"){
        mensagem = argv[2];
        
        arquivo_saida << mensagem << std::endl;
        std::cout << "Mensagem Adicionada" << std::endl;
        return 0;
    }

    //./prog list
    int line_number = 0;
    if(comando == "list"){
        while(!arquivo_entrada.eof()){
            ++line_number;
            std::getline(arquivo_entrada, mensagem);
            if(mensagem.size() == 0){
                continue;
            }
            std::cout << line_number << ". " << mensagem << std::endl;
        }

        return 0;
    }    

    //./prog add
    std::cout << "Digite uma mensagem: ";
    std::getline(std::cin, mensagem);
    arquivo_saida << mensagem << std::endl; 
    std::cout << "Mensagem Adicionada" << std::endl;


    return 0;
}