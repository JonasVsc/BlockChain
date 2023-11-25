#include<ctime>
#include"user.h"

enum status {rejected, pending, confirmed };

class Transaction {

    public:

    private:
        float amount;
        User sender;
        User recipient;
        std::string signature;
        std::string hash;
        std::time_t timestamp;
        float fee;
        int status;
        // Smart contract ?
        // Transaction Version ?
        

};