#include <iostream>
#include <fstream> //Manipular arquivos
#include <string>

int main(int argc, char* argv[]){

    std::ifstream arquivo_entrada{"nomearquivo.txt"}; //cin
    std::ofstream arquivo_saida{"arquivo.txt", std::ios::app}; //cout //std::ios::app faz com que a escrita seja no final do arquivo

    if(arquivo_entrada.fail()){
        //verificar se arquivo de entrada existe
        std::cout << "Arquivo não encontrado." << std::endl;
        return 1;
    }

    std::string nome;
    arquivo_entrada >> nome; //ou arquivo_entrada.getline() para pegar uma linha inteira
    arquivo_saida << nome << std::endl;
    
    return 0;
}