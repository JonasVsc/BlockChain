#include<iostream>
#include<ctime>

enum Status {Invalido, Valido};

struct Block {
    int index, nonce, status;
    std::time_t timestamp;
    std::string data, hash;
    Block* next;
    Block* prev;
};