#include<iostream>
#include"blockchain.h"

int main() {
    
    Blockchain blockchain;
    char option;
    std::string data, status, nonce_time;
    std::time_t timestamp;

    while(true)
    {

        std::cout
        << "# [" << blockchain.selected->index << "] " << '\n'
        << "Nonce " << blockchain.selected->nonce << " " << "\n\n"
        << "Data: " << blockchain.selected->data << "\n\n"
        << "Hash: " << blockchain.selected->hash << '\n'
        << "PrevHash: " << (blockchain.selected != blockchain.genesis ? blockchain.selected->prev->hash : "0000") << "\n\n"
        << "===========================================================================" << "\n\n";

        std::cout 
        << "[0] -> Sair" << '\n'
        << "[1] -> Inserir Dados" << '\n'
        << "[2] -> Minerar" << '\n'
        << "[3] -> Listar Blocos" << '\n';
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
        case '3':
            system("cls");
            blockchain.printBlockchain();
            system("pause");
            break;
        default:
            break;
        }
        system("cls");
    }


    system("pause");
    return 0;
}
