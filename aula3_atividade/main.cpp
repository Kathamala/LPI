#include <iostream>
#include <fstream>
#include <string>
//Atividade: Escrever com o add no arquivo

int main(int argc, char* argv[]){
    std::ofstream arquivo_saida("arquivo_saida", std::ios::app);
    std::string mensagem;
    std::string comando;

    //./prog
    if(argc == 1){
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return -1;
    }
    
    //Verificar se começa com add
    comando = argv[1];
    if(comando != "add"){
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return -1;
    }

    //./prog add mensagem
    if(argc > 2){
        for(int i = 0; i < argc - 2; i++){
            mensagem += argv[i+2];
            mensagem += " ";
        }
        
        arquivo_saida << "Mensagem Adicionada: " << mensagem << std::endl;
        return 0;
    }

    //./prog add
    std::cout << "Digite uma mensagem: ";
    std::getline (std::cin, mensagem);
    arquivo_saida << "Mensagem Adicionada: " << mensagem << std::endl;    

    return 0;
}