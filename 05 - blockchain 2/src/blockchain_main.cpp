#include<iostream>
#include<thread>

#include"blockchain.h"
#include"wallet.h"


int main()
{
    Blockchain blockchain;
    Crypto amount;
    Sender sender;
    Receiver receiver;
    char opt;

    
    while(true)
    {
        system("cls");

        std::cout << "Thread [] Saldo: " << '\n' << '\n';

        std::cout
        << "[0] - Finalizar" << '\n'
        << "[1] - Realizar Transacao" << '\n'
        << "[2] - Historico de Transacoes da Conta" << '\n'
        << "[3] - Buscar Transacao" << '\n'
        << "[4] - Minerar" << '\n'
        << "[5] - Criar Carteira" << '\n'
        << "[6] - Criar Thread" << '\n'
        << "[7] - Selecionar Thread" << '\n'
        << "[8] - Listar Transacoes de um bloco" << '\n';
        





        std::cin >> opt;

        
        if(opt == '0')
        {
            exit(0);
        }

        if(opt == '1')
        {
            system("cls");

            Transaction* transaction = new Transaction;

            std::cout << "Transacao\n\n";
            std::cout << "Quantia: ";
            std::cin >> amount;

            std::cout << "De: ";
            std::cin >> sender;

            std::cout << "Para: ";
            std::cin >> receiver;
            
            system("cls");

            std::cout 
            << "Enviando" << amount << '\n'
            << "De: " << sender << '\n'
            << "Para: " << receiver;

        }

        if(opt == '5')
        {
            system("cls");
            Wallet* wallet = new Wallet;
            
            std::cout
            << "Nova carteira criada" << '\n' << '\n'
            << "Chave Privada: \n" << wallet->privateKey << '\n' << '\n'
            << "Chave Publica: \n" << wallet->publicKey << '\n' << '\n';

            std::cout << "\nAnote suas chaves!\n\n";

            system("pause");
        }
    }

    return 0;
}