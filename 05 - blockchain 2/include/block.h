#include<iostream>
#include<ctime>


struct Block {
    Block* next;
    
    struct Head {
        int nonce;
        std::string previousBlockHash;
        std::time_t timestamp;

    };

    struct Body {
        std::string merkleRoot;
        std::string transaction;
    };
    
};
