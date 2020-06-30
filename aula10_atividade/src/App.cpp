#include "../include/App.h"

#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename)
{
}

int App::run(int argc, char* argv[])
{
    programname = argv[0];
    if (argc == 1) {
        return show_usage();
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        list_messages();
    } else if (action == "search") {
        search(argv[2]);
    } else {
        return show_usage();
    }

    return 0;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    diary.write();
}

void App::list_messages()
{
    for (size_t i = 0; i < diary.messages_size; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }
}

void App::search(std::string what){
    Message* result = diary.search(what);
    if(result != nullptr){
        std::cout << "Encontrado!" << std::endl;
        std::cout << "Primeira ocorrência em: " << result->content << std::endl;
        return;
    }
    std::cout << "Nada foi encontrado." << std::endl;
}

int App::show_usage()
{
    std::cout << "Uso: " << programname << " add <mensagem>" << std::endl;
    std::cout << "Uso: " << programname << " list" << std::endl;    
    std::cout << "Uso: " << programname << " search <argument>" << std::endl; 
    return 1;
}
  