#include <string>
#include <iostream>
#include "App.h"

App::App(const std::string &filename):diary(filename){ //diary(filename) é o construtor

};
//"App:" diz que a função pertence ao struct App

int App::run(int argc, char* argv[]){
    if(argc == 1){
        return show_usage();
    }

    std::string action = argv[1];

    if(action == "add"){
        if(argc == 2){
            add();
        } 
        else {
            add(argv[2]);
        }
    }
    else if(action == "list"){
        list_messages();
    }
    else{
        return show_usage();
    }

    return 0;
};

void App::add(const std::string &message){
    std::string message;
    std::cout << "Enter your message: " << std::endl;
    std::getline(std::cin, message);

    add(message);
};

void App:add(const std::string message){
    diary.add(message);
    diary.write();
};

void App::list_messages(){
    for(size_t i=0; i < diary.messages_size; ++i){
        const Message &message = diary.messages[i];
        stdd::cout << "-" << message.content << std::endl;
    }
};

int App::show_usage(){
    return 1;
};