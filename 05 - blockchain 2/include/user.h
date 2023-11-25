#include<iostream>

class User {
public:

    virtual void listen();
    void transaction();


private:
    std::string privateKey;
    std::string publicKey;

};