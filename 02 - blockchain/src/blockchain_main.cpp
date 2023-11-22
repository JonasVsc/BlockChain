#include<iostream>
#include"blockchain.h"

int main() {
    
    Blockchain blockchain;
    char option;
    std::string data, status, nonce_time;
    std::time_t timestamp;

    while(true)
    {

        blockchain.printBlockchain();

        std::cout 
        << "[0] -> Sair" << '\n'
        << "[1] -> Inserir Dados" << '\n'
        << "[2] -> Minerar" << '\n';
        std::cin >> option;
        
        switch (option)
        {
        case '0':
            return 0;
        case '1':
            system("cls");
            std::cout << "Data: ";
            std::cin.ignore();
            std::getline(std::cin , data);
            blockchain.setData(data);
            break;
        case '2':
            system("cls");
            blockchain.mine();
            break;
        default:
            break;
        }
        system("cls");
    }


    system("pause");
    return 0;
}
