#include<iostream>
#include<string>
#include"block.h"


class Blockchain {
    public:
    Blockchain();

    void addTransaction();

    void listTransactions();

    
        
    Block* genesis;
    Block* atual;
};

