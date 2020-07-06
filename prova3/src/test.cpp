#include "../include/Date.h"
#include "../include/Time.h"
#include "../include/Diary.h"
#include "../include/Helper.h"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{    
    Diary d("diary.txt");

    d.add("Mensagem A");
    d.add("Mensagem B");
    d.add("Mensagem C");
    d.add("Mensagem D");
    d.add("Mensagem E");

    d.write();

    return 0;
}
