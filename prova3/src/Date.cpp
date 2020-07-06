#include "../include/Date.h"
#include <sstream>
#include <string>

Date::Date() : year(0), month(0), day(0)
{
} 

void Date::set_from_string(const std::string& date){
    std::stringstream stream(date);
    char discard;
    stream >> day;
    stream >> discard;
    stream >> month;
    stream >> discard;
    stream >> year;
}

std::string Date::to_string(){
    std::stringstream ss;
    if(day < 10){
        ss << '0';
    }
    ss << day << "/";

    if(month < 10){
        ss << '0';
    }    
    ss << month << "/" << year;

    return ss.str();
}