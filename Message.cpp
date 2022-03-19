#ifdef _WIN32 
#define _CRT_SECURE_NO_WARNINGS // allow use of gmtime
#endif

#include "Message.h"
#include <ctime>    
#include <iostream> 

Message::Message(const string& sender, const string& receiver,
    const string& subject, const string& content) :
    id{ ++id_next }, author{ sender }, recipient{ receiver },
    subject{ subject }, content{ content }
{
    time_t now = time(0);
    char buffer[24]; 
    size_t count = strftime(buffer, sizeof(buffer), "%m/%d/%Y", gmtime(&now));
    if (count > 0)
        date = buffer;
    else
        date = "1/1/1900";
}

Message::Message(const string& sender, const string& receiver,
    const string& date, const string& subject, const string& content) :
    id{ ++id_next }, author{ sender }, recipient{ receiver }, date{ date },
    subject{ subject }, content{ content } {}

void Message::display_message() const
{
    cout << "Message ID: " << id << endl;
    cout << "Date: " << date << endl;
    cout << "From: " << author << endl;
    cout << "Subject: " << subject << endl;
    cout << "Message: " << endl;
    cout << content << endl;
    cout << "----------------------" << endl;
}

void Message::display_properties() const
{
    cout << "[" << id << "] ";
    cout << "Message from " << author << " at " << date
        << " - Subject: " << subject;
    cout << endl;
}

int Message::get_id() const
{
    return id;
}

int Message::id_next = 0;
