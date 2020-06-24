#include "../include/Diary.h"
#include <iostream>

Diary::Diary(const std::string& filename) : messages_size(0), messages_capacity(10), messages(nullptr)
{
    messages = new Message[messages_capacity];
}

void Diary::add(const std::string& message)
{
    // adicionar mensagem no array de mensagens
    messages[messages_size].content = message;
    messages_size++;
    
    //Esse cout é só para teste:
    std::cout << messages[messages_size-1].content << ": " << messages_size << std::endl;


}

void Diary::write()
{
    // gravar as mensagens no disco
}