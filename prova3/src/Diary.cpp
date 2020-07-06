#include "../include/Diary.h"
#include "../include/Helper.h"

#include <sstream> 
#include <fstream>
#include <iostream>

Diary::Diary(const std::string& name) : filename(name)
{
    //Carregar as mensagens previamente salvas
    std::fstream read_file(filename, std::ios::in);
    std::string linha;
    std::string date;
    std::string time;
    Date d;
    Time t;

    if(!read_file.is_open()){
        std::cout << "Erro ao abrir o arquivo. O arquivo será criado." << std::endl;
        std::ofstream file(filename);
        return;
    }

    while (!read_file.eof())
    {
        getline(read_file, linha);
        if(linha[0] == '#'){
            date = linha.substr(2, 10);
            d.set_from_string(date);
        }
        if(linha[0] == '-'){
            time = linha.substr(2, 8);
            t.set_from_string(time);
            linha = linha.substr(11);

            Message m;
            m.date = d;
            m.time = t;
            m.content = linha;
            messages.push_back(m);
        }
    }
}

void Diary::add(const std::string& message)
{

    Date d;
    Time t;
    d.set_from_string(get_current_date());
    t.set_from_string(get_current_time());

    Message m;
    m.content = message;
    m.date = d;
    m.time = t;

    messages.push_back(m);
}

std::vector<Message*> Diary::search(std::string what){
    std::vector<Message*> result;
    for(int i = 0; i < messages.size(); ++i){
        if(messages[i].content.find(what) != std::string::npos){
            //return &messages[i];
            result.push_back(&messages[i]);
        }
    }
    return result;
}

void Diary::write()
{
    bool verificador = false;
    
    std::fstream write_file(filename, std::ios::out);
    // gravar as mensagens no disco
    for(int i=0; i < messages.size(); ++i){
        std::fstream read_file(filename, std::ios::in);
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