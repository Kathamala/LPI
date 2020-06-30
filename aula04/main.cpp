#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]){

    std::ifstream file("messages.txt");

    //verificar se arquivo foi aberto
    if(!file.is_open()){
        std::cerr << "Arquivo não existente ou sem permissão de leitura" << std::endl; 
        return -1;
    }

    int line_number = 0;
    std::string message;
    //imprimir arquivo por completo. eof -> end of file
    while(!file.eof()){
        ++line_number;
        std::getline(file, message);
        //Não imprimir a linha final se estiver vazia
        if(message.size() == 0){ //No c++, .size() retorna o tamanho em bytes, não a quantidade de caracteres
            continue;
        }
        std::cout << line_number << ". " << message << std::endl;
    }

    file.close();

    return 0;
}