#include<iostream>
#include<ctime>
#include"transaction.h"


struct Block {
    Block* next;
    
    struct Head {
        int nonce;
        std::string previousBlockHash;
        std::time_t timestamp;

    };

    struct Body {
        std::string merkleRoot;
        Transaction* transactions;
    };
    
};
