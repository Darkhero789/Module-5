#ifndef message_store_h
#define message_store_h

#include <fstream>  
#include <list>
#include <map>
#include <string>
#include "message.h"

using namespace std;

class MessageStorage
{
public:
    MessageStorage() = default;

    MessageStorage(const string& filename);

    void display_messages_for_user(const string& user) const;

    void read_message(const string& user, int msg_id) const;

    void delete_message(const string& user, int msg_id);

    void send_message(const string& sender, const string& receiver,
        const string& subject, const string& content);

    void save_message_store(const string& filename);

private:
    map<string, list<Message>> messages;

    void read_messages_from_file(const string& filename);

    void write_messages_to_file(const string& filename);
};

#endif