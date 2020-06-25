#include "../include/Diary.h"
#include <iostream>

//Inicializar variaveis aqui
Diary::Diary(const std::string& name): //Construtor
    filename(name),
    messages(nullptr),
    messages_size(0), //Valor padrão já é 0, essa linha é só pra esclarecer
    messages_capacity(10)
{
    messages = new Message[messages_capacity];
}

//Deletar variáveis aqui
Diary::~Diary(){ //Destrutor, deleta as variáveis logo antes de qualquer return
    delete[] messages;
}
//RAII = resource acquisition is initialization

void Diary::add(const std::string& message)
{
    if(messages_size == messages_capacity){
        return;
    }

    Message m;
    m.content = message;
    messages[messages_size] = m;
    messages_size++;
}

void Diary::write()
{
    // gravar as mensagens no disco
}