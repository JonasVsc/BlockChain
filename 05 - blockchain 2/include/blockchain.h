#include<iostream>
#include<string>
#include"block.h"


class Blockchain {
    public:
    Blockchain();

    void addTransaction(Transaction& transaction);

    void listTransactions();

    
        
    Block* genesis;
    Block* atual;
};

