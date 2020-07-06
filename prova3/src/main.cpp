#include "../include/App.h"
#include "../include/Config.h"

#include <string>
#include <fstream>

#include <iostream>

int main(int argc, char* argv[])
{
    Config c;
    std::string path;
    std::string format;

    std::ifstream read_file("diary.config", std::ios::in);
    if(read_file.fail()){
        std::ofstream outfile ("diary.config");
        outfile << "path=diary.md" << std::endl;
        outfile << "default_format=%d %t: %m" << std::endl;

        path = "path=diary.md";
        format = "default_format=%d %t: %m";
    }
    else{
        std::string temp;
        while(!read_file.eof()){
            getline(read_file, temp);
            if(temp.find("path=") != std::string::npos){
                path = temp;
            } else if (temp.find("default_format=") != std::string::npos){
                format = temp;
            }            
        }
    }

    path = c.set_path_from_string(path);
    format = c.set_format_from_string(format);

    App aplicativo(path);
    aplicativo.path = path;
    aplicativo.format = format;

    return aplicativo.run(argc, argv);
}
