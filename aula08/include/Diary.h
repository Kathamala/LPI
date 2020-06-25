#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Message.h"

#include <string>

struct Diary
{
    //Construtor:
    Diary(const std::string& filename);

    //Destrutor, sempre sem parâmetros:
    ~Diary();

    std::string filename;
    Message* messages;
    size_t messages_size;
    size_t messages_capacity;

    void add(const std::string& message);
    void write();
};
#endif 