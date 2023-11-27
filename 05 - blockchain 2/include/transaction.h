#include<iostream>
#include<string>
#include<ctime>

typedef std::string Sender, Receiver;
typedef float Crypto;

enum Status {rejected, pending, confirmed };

struct Transaction {
    int id;
    Sender sender;
    Receiver receiver;
    Crypto amount;

};
