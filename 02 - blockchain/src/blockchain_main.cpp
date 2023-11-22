#include<iostream>
#include"blockchain.h"

int main() {
    
    Blockchain blockchain;
    char option;
    std::string data;

    while(true)
    {
        std::cout
        << "# [" << blockchain.actual->index << "] " << "STATUS" << "\n\n"
        << "Nonce " << blockchain.actual->nonce << " - " << blockchain.getGenesisTimestamp() << '\n'
        << "Data: " << blockchain.actual->data << "\n\n"
        << "Hash: " << "ab88d76aa9deef9f72" << '\n'
        << "PrevHash: " << "ab88d76aa9deef9f72" << '\n'
        << "===========================================" << "\n\n";


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
        default:
            break;
        }
        system("cls");
    }


    system("pause");
    return 0;
}
