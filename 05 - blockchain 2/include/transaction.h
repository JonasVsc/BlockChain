#pragma once

#include<ctime>
#include<iostream>

class Wallet;

enum Status {rejected, pending, confirmed };

class Transaction {

    public:

    private:
        float amount;
        Wallet* sender;
        Wallet* recipient;
        std::string signature;
        std::time_t timestamp;
        std::string hash;
        float fee;
        Status status;
};