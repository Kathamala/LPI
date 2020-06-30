#ifndef W5NAULA05_MESSAGE_H
#define W5NAULA05_MESSAGE_H

#include <string>

// Define the Message type

struct Date{
    int day;
    int month;
    int year;
};

struct Time{
    int seconds;
    int minutes;
    int hours;
};

struct Message {
    Date date;
    Time time;
    std::string content;

    bool compare_message(Message other_message);
    std::string get_date_as_string();
    std::string get_time_as_string();
};

#endif