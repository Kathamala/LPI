#ifndef W5N_CONFIG_H
#define W5N_CONFIG_H

#include <string>

struct Config
{
    Config();

    std::string set_path_from_string(const std::string& time);
    std::string set_format_from_string(const std::string& time);
};
#endif