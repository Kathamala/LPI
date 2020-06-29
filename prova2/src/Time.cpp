#include "../include/Time.h"
#include <sstream>
#include <string>

Time::Time() : hour(0), minute(0), second(0)
{
} 

void Time::set_from_string(const std::string& time){
    std::stringstream stream(time);
    char discard;
    stream >> hour;
    stream >> discard;
    stream >> minute;
    stream >> discard;
    stream >> second;
}

std::string Time::to_string(){
    std::stringstream ss;

    if(hour < 10){
        ss << '0';
    }
    ss << hour << ":";

    if(minute < 10){
        ss << '0';
    }    
    ss << minute << ":";
    
    if(second < 10){
        ss << '0';
    }      
    ss << second;

    return ss.str();

}