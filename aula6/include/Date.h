#ifndef W5N_DATE_H
#define W5N_DATE_H

#include <string>

struct Date{
    unsigned year;
    unsigned month;
    unsigned day;
    //Unsigned não pega números negativos. É implícito que é "unsigned int".

    void set_from_string(const std::string &date);
    //Separar string dd:mm:aaaa, e preencher as variáveis day, month, year.

}; 

#endif