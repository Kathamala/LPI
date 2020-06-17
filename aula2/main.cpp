#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    //argc -> quantidade de parametros passados para main
    //argv -> parametros passados para main
    std::string nome;

    if(argc == 1){
        std::cout << "Uso: " << argv[0] << " <nome>" << std::endl;
        return -1;
    }
    std::cout << "Olá, " << argv[1] << std::endl;

    return 0;
}