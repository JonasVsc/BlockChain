#include<iostream>
#include<string>
#include"block.h"
#include"hash.h"

const std::string difficulty = "0000";

class Blockchain {
    public:
        Blockchain();
        void setTimestamp();
        void setData(const std::string &d);
        void printBlockchain();
        void printSelected();
        void mine();
        void newBlock();
        void selectBlock(int& index);

        Block* genesis;
        Block* actual;
        Block* selected;
    private:

};