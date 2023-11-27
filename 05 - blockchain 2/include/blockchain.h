#include<iostream>
#include<string>
#include"block.h"
#include"signatures.h"


class Blockchain {
public:
    Blockchain();
    void addTransaction();
    void addTransaction(const std::string& receiver, const Crypto& amount) const;
    void mine(const std::string& publKey);
    void newBlock();
    void listTransactions(const std::vector<Transaction>& transactions) const;
    void recalculateHash();
        
    Block* genesis;
    Block* atual;
};