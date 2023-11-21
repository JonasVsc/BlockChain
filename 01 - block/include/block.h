#include<iostream>

const std::string difficulty = "0000";

class Block {
public:
    Block();
    
    void mine();

    int getIndex();
    int getNonce();
    
    std::string getData();
    std::string getHash();
    int getStatus();

    void setData(const std::string &data_);

private:
    int nonce, index, status;
    std::string hash;
    std::string data;

    void setHash(const std::string &data_);
    void setStatus(int st);
};
