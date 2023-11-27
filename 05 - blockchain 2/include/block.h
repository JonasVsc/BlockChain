#include<iostream>
#include <vector>
#include<ctime>
#include"transaction.h"

enum status_nonce {Invalido, Valido};

struct Block {
    Block* previous;
    
    //Header
    int nonce, index;
    status_nonce status;
    std::string previousHash;
    std::string hash;
    std::time_t timestamp;
    Crypto reward;

    //Body
    std::vector<Transaction> transactions;
};
