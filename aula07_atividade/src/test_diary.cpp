#include <iostream>
#include <cassert>
#include "../include/Diary.h"

int main(int argc, char* argv[])
{
    Diary d("Arquivo");

    d.add("Mensagem1");
    d.add("Mensagem2");
    d.add("Mensagem3");
    d.add("Mensagem4");
    d.add("Mensagem5");
    d.add("Mensagem6");            
    d.add("Mensagem7");      
    d.add("Mensagem8");      
    d.add("Mensagem9");      
    d.add("Mensagem10");   

    assert(d.messages_size == 10);
    std::cout << "Sucesso, o array de mensagens tem exatamente 10 termos!" << std::endl;


}