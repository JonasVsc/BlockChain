#include<iostream>
#include <vector>
#include<ctime>
#include"transaction.h"


struct Block {
    Block* previous;
    
    //Header
    int nonce, index;
    std::string previousHash;
    std::string hash;
    std::time_t timestamp;
    Crypto reward;

    //Body
    std::string merkleRoot;
    std::vector<Transaction> transactions;
    
};
