#include "../include/Diary.h"
#include "../include/Helper.h"

#include <sstream>

Diary::Diary(const std::string& name) : filename(name), messages(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];
}

Diary::~Diary()
{
    delete[] messages;
}

void Diary::add(const std::string& message)
{
    if (messages_size >= messages_capacity) {
        return;
    }

    Date d;
    Time t;
    d.set_from_string(get_current_date());
    t.set_from_string(get_current_time());

    Message m;
    m.content = message;
    m.date = d;
    m.time = t;

    messages[messages_size] = m;
    messages_size++;
}

void Diary::write()
{
    // gravar as mensagens no disco
}
