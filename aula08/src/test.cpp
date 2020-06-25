#include <iostream>
#include "../include/Diary.h"

#include <sstream> //strings

int main(int argc, char* argv[])
{
    std::string date = "25/06/2020 asd asd asd";
    Date d;

    std::stringstream stream(date); //O stream está lendo date, nessa caso
    //Usar um string para ler, e outro pra escrever
    //stream >> variável;
    //stream << "Teste";
    char discard;
    stream >> d.day;
    stream >> discard;
    stream >> d.month;
    stream >> discard;
    stream >> d.year;
    //O discard tira as barras da data. O stream pega o dia, descarta
    //a barra, pega o mes, descarta a barra, pega o ano, e descarta
    //a barra.
    /*
    m.content = content
    m.date = d;
    m.time = t;
    */

    std::cout << d.day << d.month << d.year << std::endl;
    
    return 0;
}