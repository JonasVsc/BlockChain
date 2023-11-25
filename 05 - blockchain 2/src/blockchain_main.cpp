#include<iostream>
#include<thread>
#include <windows.h>
#include"blockchain.h"
#include"wallet.h"


int main()
{
    Blockchain blockchain;
    int index;
    char opt;
    std::thread* selectedThread;

    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    std::cout << "Numero maximo de threads suportado pelo sistema: " << systemInfo.dwNumberOfProcessors << '\n';
    system("pause");

    std::thread* Thread = new std::thread [systemInfo.dwNumberOfProcessors - 1];

    
    while(true)
    {
        system("cls");

        std::cout << "Thread [" << index <<  "]" << '\n' << '\n'
        << "Saldo 00 Crypto" << '\n' << '\n';

        std::cout
        << "[0] - Finalizar" << '\n'
        << "[1] - Selecionar Thread" << '\n'
        << "[2] - Criar Carteira" << '\n';
        std::cin >> opt;


        if(opt == '1')
        {
            std::cout << "Thread: ";
            std::cin >> index;
            if(index < systemInfo.dwNumberOfProcessors)
            {
                selectedThread = &Thread[index];
            } else {
                std::cerr << "Erro, Thread Invalida" << '\n';
                index = 0;
                system("pause");
            }
        }











        if(opt == '0')
        {
            exit(0);
        }
    }

    return 0;
}