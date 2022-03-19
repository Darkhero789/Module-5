#if (defined(_WIN32) || defined(__linux__))
#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif /* _WIN32 */
#include <cstdarg>
#include <ctime>
#endif
#include <iostream>
#include "Message_Storage.h"

void user_login(MessageStorage& store);
using namespace std;

int main()
{
    string username;
    string input;
    int Message_id;
    string receiver;
    string subject;
    string message;
    bool loop = true;
    MessageStorage store("Sample_messages.txt");
    cout << "Hello and Welcome to the chat program\n";
    while (username != "quit") {
        cout << "\nPlease enter your username(enter quit to exit) : ";
        cin >> username;
        if (username != "quit") {
            loop = true;
            cout << "\nWelcome " << username << "\n";
            time_t now = time(0);
            string currentDateAndTime = ctime(&now);
            ///cout << "It is now " << currentDateAndTime << endl;
            while (loop == true) {
                cout << "Pick an option:\n\td - display all messages\n\tr - read a messages\n";
                cout << "\tx - delete a message\n\ts - send a message\n\tq - exit user\n";
                cin >> input;
                if (input == "q") {
                    loop = false;
                    cout << "\nGoodbye " << username << "\n";
                }
                else if (input == "d") {
                    store.display_messages_for_user(username);
                }
                else if (input == "r") {
                    cout << "Message ID: ";
                    cin >> Message_id;
                    if (Message_id < 0) {
                        cout << "Invalid ID";
                    }
                    else {
                        store.read_message(username, Message_id);
                    }
                }
                else if (input == "x") {
                    cout << "Message ID: ";
                    cin >> Message_id;
                    if (Message_id < 0) {
                        cout << "Invalid ID";
                    }
                    else {
                        store.delete_message(username, Message_id);
                    }
                }
                else if (input == "s") {
                    getline(cin, receiver);
                    cout << "Who is the message for? ";
                    getline(cin, receiver);
                    cout << "What is the subject of the message? ";
                    getline(cin, subject);
                    cout << "What is the message? ";
                    getline(cin, message);
                    store.send_message(username, receiver, subject, message);
                }
                else {
                    cout << "Invalid response";
                }
            }
        }
    }
}
