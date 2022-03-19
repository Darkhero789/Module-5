#ifndef message_h 
#define message_h

#include <string>

using namespace std;

class Message {

public:

    Message(const string& sender, const string& receiver, const string& subject,
        const string& content);

    Message(const string& sender, const string& receiver, const string& date,
        const string& subject, const string& content);

    int get_id() const;

    void display_message() const;

    void display_properties() const;

    string get_sender() const { return author; }
    string get_receiver() const { return recipient; }
    string get_date() const { return date; }
    string get_subject() const { return subject; }
    string get_contents() const { return content; }

private:
    int id;
    static int id_next;
    string author;
    string recipient;
    string date;
    string subject;
    string content;
};

#endif