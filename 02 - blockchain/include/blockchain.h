#include"block.h"

class Blockchain {
    public:
        Blockchain();
        


        Block* genesis;
        Block* actual;
    private:

        std::string getGenesisTimestamp();
};