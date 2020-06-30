#include "../include/Diary.h"
#include "../include/Helper.h"

#include <sstream>
#include <fstream>
#include <iostream>

Diary::Diary(const std::string& name) : filename(name), messages(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];
    //Carregar as mensagens previamente salvas
    std::fstream read_file(filename, std::ios::in);
    std::string linha;
    std::string date;
    std::string time;
    Date d;
    Time t;

    if(!read_file.is_open()){
        std::cout << "Erro ao abrir o arquivo" << std::endl;
        return;
    }

    while (!read_file.eof())
    {
        if (messages_size >= messages_capacity) {
            increase_capacity();
        }
        getline(read_file, linha);
        if(linha[0] == '#'){
            date = linha.substr(2, 10);
            d.set_from_string(date);
        }
        if(linha[0] == '-'){
            time = linha.substr(2, 8);
            t.set_from_string(time);
            linha = linha.substr(11);
            messages[messages_size].date = d;
            messages[messages_size].time = t;
            messages[messages_size].content = linha;
            ++messages_size;
        }
    }
}

Diary::~Diary()
{
    delete[] messages;
}

void Diary::add(const std::string& message)
{
    if (messages_size >= messages_capacity) {
        increase_capacity();
    }

    Date d;
    Time t;
    d.set_from_string(get_current_date());
    t.set_from_string(get_current_time());

    Message m;
    m.content = message;
    m.date = d;
    m.time = t;

    messages[messages_size] = m;
    messages_size++;
}


Message* Diary::search(std::string what){
    for(int i = 0; i < messages_size; ++i){
        if(messages[i].content.find(what) != std::string::npos){
            return &messages[i];
        }
    }
    return nullptr;
}

void Diary::write()
{
    bool verificador = false;
    
    std::fstream write_file("diary.txt", std::ios::out);
    // gravar as mensagens no disco
    for(int i=0; i < messages_size; ++i){
        std::fstream read_file("diary.txt", std::ios::in);
        //verificar se data já existe
        std::string comparador;
        while(!read_file.eof()){
            getline(read_file, comparador);
            if(comparador == "# " + messages[i].date.to_string()){
                write_file << "- " << messages[i].time.to_string() << " " << messages[i].content << std::endl;
                verificador = true;
            }
        }
        if(verificador){
            verificador = false;
            continue;
        }

        write_file << "\n# " << messages[i].date.to_string() << std::endl << "\n- " << messages[i].time.to_string() << " " << messages[i].content << std::endl;
    }
} 

void Diary::increase_capacity(){
    Message *messages2 = new Message[messages_capacity*2];
    for(int i = 0; i < messages_capacity; ++i){
        messages2[i] = messages[i];
    }
    delete[] messages;
    messages = messages2;

    messages_capacity *= 2;
} 
