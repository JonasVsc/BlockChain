#include<iostream>
#include<thread>

#include"blockchain.h"
#include"wallet.h"
#include"miner.h"

int main()
{
    Blockchain blockchain;
    char opt, role;

    do {
        system("cls");
        std::cout
        << "[0] - Exit" << '\n'
        << "[1] - Connect" << '\n';
        std::cin >> opt;

        if(opt == '0')
        {
            return 0;
        }

    } while(opt != '1');

    while (true)
    {
        system("cls");
        std::cout
        << "0 -> User" << '\n'
        << "1 -> Miner" << '\n';
        std::cin >> role;

        if(role == '0')
        {
            User user;
            break;
        }
        if(role == '1')
        {
            Miner miner;
            break;
        }
    }



    system("pause");
    return 0;
}