#include<iostream>
#include"block.h"



int main() {
    Block block;
    char option;
    std::string data;

    
    while(true)
    {

        std::cout
        << "=====================================================================================\n\n"
        << "STATUS: " << block.getStatus() << "\n\n"
        << "Bloco : " << block.getIndex() << "\n\n"
        << "Nonce : " << block.getNonce() << "\n\n"
        << "Dados : " << block.getData() << "\n\n"
        << "Hash  : " << block.getHash() << "\n\n"
        << "=====================================================================================\n\n";

        std::cout
        << "\n\nOptions:\n\n"
        << "[0] - Sair\n"
        << "[1] - Inserir dados\n"
        << "[2] - Minerar\n";
        std::cin >> option;
        std::cout << "\n\n";

        if(option == '0')
        {
            return 0;
        }
        if(option == '1')
        {
            std::cout << "Data: ";
            std::cin.ignore();
            std::getline(std::cin, data);
            block.setData(data);
            std::cout << "\n\n";
        }
        if(option == '2')
        {

        }

        system("cls");
    }


    
    system("pause");
    return 0;
}
