#include "../include/Date.h"
#include "../include/Time.h"
#include "../include/Diary.h"
#include "../include/Helper.h"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
    Diary di("Arquivo");

    di.add("Mensagem1");
    di.add("Mensagem2");
    di.add("Mensagem3");
    di.add("Mensagem4");
    di.add("Mensagem5");
    di.add("Mensagem6");            
    di.add("Mensagem7");      
    di.add("Mensagem8");      
    di.add("Mensagem9");      
    di.add("Mensagem10");  

    std::cout << "Date: " << di.messages[0].date.day << "/" << di.messages[0].date.month << "/" << di.messages[0].date.year <<  std::endl;
    std::cout << "Time: " << di.messages[0].time.hour << ":" << di.messages[0].time.minute << ":" << di.messages[0].time.second <<  std::endl;
    std::cout << "Content: " << di.messages[0].content <<  std::endl;

    return 0;
}
