#include<iostream>
#include<string>
#include"block.h"
#include"hash.h"

const std::string difficulty = "0000";

class Blockchain {
    public:
        Blockchain();
        std::string getGenesisTimestamp();
        void setTimestamp();
        void setData(const std::string &d);
        void setHash(const std::string &d);
        void printBlockchain();
        void mine();

        Block* genesis;
        Block* actual;
    private:

};