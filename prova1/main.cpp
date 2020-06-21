#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

std::string format_current_date(const std::string& format){
    std::time_t time = std::time(nullptr);
    char result[1024];
    std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));
    return std::string(result);
}

std::string get_current_date(){
    return format_current_date("%d/%m/%Y");
}

std::string get_current_time(){
    return format_current_date("%H:%M:%S");
}

int main(int argc, char* argv[]){
    
    std::string data;
    std::string tempo;

    std::fstream file("file.txt", std::ios::in | std::ios::out | std::ios::app); //abrir arquivo para leitura e escrita com append
    std::string mensagem;
    std::string comando;

    //verificar se arquivo foi aberto
    if(!file.is_open()){
        std::cerr << "O arquivo não pode ser criado" << std::endl; //cerr imprime como um erro
        return -1;
    }

//./prog
    if(argc == 1){
        std::cerr << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        std::cerr << "Uso: " << argv[0] << " list" << std::endl;
        return -1;
    }
    
    //Verificar se começa com add
    comando = argv[1];
    if(comando != "add" && comando != "list"){
        std::cerr << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        std::cerr << "Uso: " << argv[0] << " list" << std::endl;
        return -1;
    }

//./prog add mensagem
    if(argc > 2 && comando == "add"){
        mensagem = argv[2];

        std::string comparador;
        tempo = get_current_time();
        data = get_current_date();

        std::fstream read_file("file.txt", std::ios::in);
        //verificar se data já existe
        while(!read_file.eof()){
            getline(read_file, comparador);
            if(comparador == "# " + data){
                file << "- " << tempo << " " << mensagem << std::endl;
                std::cout << "Mensagem Adicionada" << std::endl;
                
                return 0;
            }
        }

        file << "\n# " << data << std::endl << "\n- " << tempo << " " << mensagem << std::endl;
        std::cout << "Mensagem Adicionada" << std::endl;
        return 0;
    }

//./prog list
    if(comando == "list"){
        while(!file.eof()){
            std::getline(file, mensagem);
            if(mensagem.size() == 0){
                continue;
            }
            if(mensagem[0] == '#'){
                continue;
            }
            std::cout << mensagem << std::endl;
        }

        return 0;
    }    

//./prog add
    std::cout << "Digite uma mensagem: ";
    std::getline(std::cin, mensagem);

    tempo = get_current_time();
    data = get_current_date();

    std::fstream read_file("file.txt", std::ios::in);
    std::string comparador;
    //verificar se data já existe
    while(!read_file.eof()){
        getline(read_file, comparador);
        if(comparador == "# " + data){
            file << "- " << tempo << " " << mensagem << std::endl;
            std::cout << "Mensagem Adicionada" << std::endl;
            
            return 0;
        }
    }

    file << "\n# " << data << std::endl << "\n- " << tempo << " " << mensagem << std::endl;
    std::cout << "Mensagem Adicionada" << std::endl;
    
    return 0;
}