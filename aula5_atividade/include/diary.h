#ifndef W5NAULA05_DIARY_H
#define W5NAULA05_DIARY_H

#include <string>

#include "message.h"

//Read and Write in files
int add(Message message, std::string file_name);
int list(std::string file_name);

#endif