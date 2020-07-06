#include "../include/App.h"
#include "../include/Config.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
        if(argc == 2){
            list_messages();
        }
        else{
            list_messages(argv[2]);
        }
    } else if (action == "search") {
        if(argc == 2){
            search();
        }
        else{
            search(argv[2]);
        }
    } else if (action == "interactive") {
        int input = -1;
        while(input != 0){
            std::cout << "===============================================" << std::endl; 
            std::cout << "Diário 1.0\n" << std::endl; 
            std::cout << "Selecione uma ação: \n" << std::endl;
            std::cout << "1) Listar mensagens\n2) Adicionar nova mensagem\n" << std::endl;
            std::cout << "0) Finalizar" << std::endl;
            std::cout << "===============================================" << std::endl; 
            std::cin >> input;

            if(input == 1){
                list_messages();
            }
            else if(input == 2){
                std::cin.ignore();
                add();
            }
        }

    }
    else {
        return show_usage();
    }

    return 0;
}

void App::add()
{
    std::string message;
    std::cout << "# Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    diary.write();
    std::cout << "# Mensagem adicionada. " << std::endl;
}

void App::list_messages()
{
    list_messages(format);
}

void App::list_messages(const std::string new_format)
{
   std::string gone;
   char compare;
   char discard;

    for(size_t i = 0; i < diary.messages.size(); ++i){
        std::stringstream ss(new_format);
        std::stringstream print_message;

        while (true) {
            ss >> std::noskipws >> compare;

            if(ss.eof()){
                break;
            }

            if(compare == '%'){
                while(compare == '%'){
                    ss >> std::noskipws >> compare;
                    if(compare == 'd'){
                        print_message << diary.messages[i].date.to_string();
                        break;
                    }
                    if(compare == 't'){
                        print_message << diary.messages[i].time.to_string();
                        break;
                    }
                    if(compare == 'm'){
                        print_message << diary.messages[i].content;
                        break;
                    }   
                    print_message << compare;
                }
            } else{
                print_message << compare;
            }
        }

        std::cout << print_message.str() << std::endl;
    }
}

void App::search(){
    std::string argument;
    std::cout << "# Enter the argument:" << std::endl;
    std::getline(std::cin, argument);

    search(argument);    
}

void App::search(std::string what){
    std::vector<Message*> result = diary.search(what);
    if(result.size() != 0){
        std::cout << "# Encontrado!" << std::endl;
        for(int i=0; i < result.size(); ++i){
            std::cout << "- " << result[i]->content << std::endl;
        }
        return;
    }
    std::cout << "# Nada foi encontrado." << std::endl;
}

int App::show_usage()
{
    std::cout << "# Uso: " << programname << " add" << std::endl;
    std::cout << "# Uso: " << programname << " add <mensagem>" << std::endl;
    std::cout << "# Uso: " << programname << " list" << std::endl;    
    std::cout << "# Uso: " << programname << " list <format>" << std::endl;   
    std::cout << "# Uso: " << programname << " search" << std::endl;
    std::cout << "# Uso: " << programname << " search <argument>" << std::endl; 
    std::cout << "# Uso: " << programname << " interactive" << std::endl;
    return 1;
}
  