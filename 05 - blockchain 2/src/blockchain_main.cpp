#include<iostream>
#include"wallet.h"

int main()
{
    Wallet wallet;


    std::cout << "Private Key: " << wallet.privateKey << '\n';
    std::cout << "Public Key: " << wallet.publicKey << '\n';

    system("pause");
    return 0;
}