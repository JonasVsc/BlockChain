#pragma once

class Wallet;

class User {
public:
    User();
    virtual void listen();
    void transaction();


private:
    Wallet* wallet;

};