#include<iostream>

const int difficulty = 0;

class Block {
public:
    Block();
    
    void mine();

    int getIndex();
    int getNonce();
    
    std::string getData();
    std::string getHash();
    std::string getStatus();

    void setData(const std::string &data_);

private:
    int nonce, index;
    std::string hash;
    std::string data;

    void setHash(const std::string &data_);
};
