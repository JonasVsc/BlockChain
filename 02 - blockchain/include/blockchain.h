#include"block.h"

class Blockchain {
    public:
        Blockchain();
        std::string getGenesisTimestamp();
        void setData(const std::string &d);
        


        Block* genesis;
        Block* actual;
    private:

};