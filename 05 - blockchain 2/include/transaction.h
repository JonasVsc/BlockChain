#include<ctime>
#include<iostream>

typedef std::string Sender;
typedef std::string Receiver;
typedef float Crypto;

class Wallet;

enum Status {rejected, pending, confirmed };

struct Transaction {
    int id;
    Sender sender;
    Receiver receiver;
    Crypto amount;
    std::string signature;
};