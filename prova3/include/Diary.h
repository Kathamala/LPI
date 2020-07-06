#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Message.h"

#include <string>
#include <vector>

struct Diary
{
    Diary(const std::string& filename);

    std::string filename;
    std::vector<Message> messages;

    void add(const std::string& message);
    std::vector<Message*> search(std::string what);
    void write();
    void increase_capacity();
};
#endif 
 