#ifndef W5N_APP_H
#define W5N_APP_H

#include "Diary.h"

#include <string>

struct App
{
    Diary diary;
    std::string programname;

    std::string path;
    std::string format;

    App(const std::string& filename);
    int run(int argc, char* argv[]);
    int show_usage();

    void add();
    void add(const std::string message);
    void list_messages();
    void list_messages(const std::string new_format);
    void search(std::string what);
    void search();
};
#endif
