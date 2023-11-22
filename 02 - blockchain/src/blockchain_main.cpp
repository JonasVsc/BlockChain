#include<iostream>
#include"blockchain.h"

int main() {
    
    Blockchain blockchain;
    char option;
    std::string data, status, nonce_time;
    std::time_t timestamp;

    while(true)
    {
        if(blockchain.actual->status == Invalido)
        {
            status = "Invalido"; 
            nonce_time = "";
        }
        if(blockchain.actual->status == Valido)
        {
            status = "Valido";
            timestamp = blockchain.actual->timestamp;
            nonce_time = std::asctime(std::localtime(&timestamp));
        }


        std::cout
        << "# [" << blockchain.actual->index << "] " << status << "\n\n"
        << "Nonce " << blockchain.actual->nonce << " " << nonce_time << '\n'
        << "Data: " << blockchain.actual->data << "\n\n"
        << "Hash: " << blockchain.actual->hash << '\n'
        << "PrevHash: " << blockchain.actual->prevHash << "\n\n"
        << "===========================================================================" << "\n\n";


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
