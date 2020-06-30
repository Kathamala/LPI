//Lista com várias mensagens
#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include <string>
#include "Message.h"

struct Diary
{
    Diary(const std::string &filename); //Construtor. Não se cria um diário sem dar um nome.

    std::string filename;
    Message *messages;
    size_t messages_size; //Quantidade de mensagens no array
    size_t messages_capacity; //Máximo número de mensagens que o array suporta
    //size_t: Maior inteiro possível que a memória suporta

    void add(const std::string &message); //Usando const, não se pode alterar a variável.
    void write();
};


#endif
