#include<iostream>
#include<string>
#include"block.h"
#include"signatures.h"


class Blockchain {
    public:
    Blockchain();

    void addTransaction();

    void mine(std::string& publKey);

    void newBlock();

    void listTransactions();

    
        
    Block* genesis;
    Block* atual;
};

