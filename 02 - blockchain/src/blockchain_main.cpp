#include<iostream>
#include"blockchain.h"

int main() {
    
    Blockchain blockchain;
    char option;

    while(true)
    {
        std::cout
        << "BLOCO " << blockchain.actual->index << '\n';

        std::cin >> option;
        if(option == '0')
        {
            std::cout << "aa";
        }
    }


    system("pause");
    return 0;
}
