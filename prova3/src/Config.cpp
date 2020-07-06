#include "../include/Config.h"
#include <string>

Config::Config()
{
}

std::string Config::set_path_from_string(const std::string& ogpath){
    return ogpath.substr(5);
}

std::string Config::set_format_from_string(const std::string& ogformat){
    return ogformat.substr(15);
}