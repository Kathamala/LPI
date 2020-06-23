//Responsável pela execução
//Comunicação entre usuário e programa
//Imprimir erros
#ifndef W5N_APP_H
#define W5N_APP_H

#include <string>
#include "Diary.h"

struct App{
    Diary diary;
    //Construtor: Função chamada quando a variável é inicializada. Um construtor é uma função com o mesmo nome da struct.
    App(const std::string &filename);
    int run(int argc, char* argv[]); //Retorna se deu certo ou não
    int show_usage();
    void add();
    void add(const std::string &message);
    void list_messages();
};

#endif