#include <iostream>
#include <fstream>
#include <string>

#include "../include/App.h"

int main(int argc, char* argv[]){

    App aplicativo("diary.md");
    return aplicativo.run(argc, argv);
}