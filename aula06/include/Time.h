#ifndef W5N_TIME_H
#define W5N_TIME_H

#include <string>

struct Time{
    unsigned hours;
    unsigned minutes;
    unsigned seconds;
    //Unsigned não pega números negativos. É implícito que é "unsigned int".

    void set_from_string(const std::string &time);
    //Separar string hh:mm:ss, e preencher as variáveis hour, minutes, seconds.

}; 

#endif