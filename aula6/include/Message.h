#ifndef W5N_MESSAGE_H
#define W5N_MESSAGE_H

#include <string>
#include "Time.h"
#include "Date.h"

struct Message{
    std::string content;
    Date date;
    Time time;
};

#endif