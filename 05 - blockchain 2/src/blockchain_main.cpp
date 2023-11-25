#include<iostream>
#include<thread>
#include <windows.h>
#include"blockchain.h"
#include"wallet.h"
#include"signatures.h"

int main()
{
    Blockchain blockchain;
    Wallet* wallet = new Wallet[10];
    std::string wallet_name;
    int numWallet = 0;
    int index = 0, search_block_index = 0;
    char opt;

    while(true)
    {
        system("cls");
        
        std::cout
        << "======================================================================" << '\n'
        << "Bloco Atual [" << "00" << ']' << '\n'
        << '\n'
        << "Nonce # " << '\n'
        << "======================================================================" << '\n'
        << '\n'
        << "[0] Detalhes de um bloco" << '\n'
        << '\n'
        << "[1] Detalhes de uma transacao" << '\n'
        << '\n'
        << "----------------------------------------------------------------------" << '\n'
        << '\n'
        << "[2] Fazer uma transacao" << '\n'
        << '\n'
        << "[3] Minerar" << '\n'
        << '\n'
        << "----------------------------------------------------------------------" << '\n'
        << '\n'
        << "[4] Listar Carteiras" << '\n'
        << '\n'
        << "[5] Criar uma carteira" << '\n'
        << '\n'
        << "----------------------------------------------------------------------" << '\n'
        << '\n';
        std::cout << ">";
        std::cin >> opt;

        if(opt == '0')
        {
            system("cls");

            std::cout << "Index Bloco: ";
            std::cin >> search_block_index;

            system("cls");

            Block* temp = new Block;
            temp = blockchain.atual;

            // aqui

            // Fazer um iterador tipo:
            // while(temp->index != search_block_index)
            // {
            //     temp = temp->previous;
            // }

            // testar valores negativos, positivos e 0 para search_block_index

            // tentar substituir o valor "00" por temp->index como teste
            system("cls");
            std::cout
            << "======================================================================" << '\n'
            << "Bloco [" << "00" << "]" << '\n' // temp->index
            << '\n'
            << "Nonce # " << '\n'
            << '\n'
            << "======================================================================" << '\n'
            << '\n'
            << '\n'
            << "[0] Listar Transacoes" << '\n'
            << '\n'
            << "[1] Voltar" << '\n'
            << '\n'
            << "----------------------------------------------------------------------" << '\n'
            << '\n';
            std::cout << ">";
            std::cin >> opt;

            if(opt == '0')
            {
                system("cls");
                blockchain.listTransactions();
                system("pause");

            }
            if(opt == '1')
            {
                continue;
            }
        }

        if(opt == '1')
        {
            //Index Bloco
            // Detalhes do bloco

            // [0] Mostrar Livro razao
            // [1] Voltar
        }

        if(opt == '2')
        {
            // De:
            // Para:
            // Quantia:

            //Confirmar
            //S ou N
        }

        if(opt == '3')
        {
            // Indicar a chave publica usada na mineração
        }

        if(opt == '4')
        {
            int i = 0;
            system("cls");

            while(!(wallet[i].name.empty()))
            {
                std::cout
                << "======================================================================" << '\n'
                << "Carteira " << wallet[i].name << '\n'
                << '\n'
                << "Chave Privada " << wallet[i].privateKey << '\n'
                << '\n'
                << "Chave Publica " << wallet[i].publicKey << '\n'
                << "======================================================================" << '\n'
                << '\n' << '\n';
                i++;
            }
            system("pause");
        }

        if(opt == '5')
        {
            system("cls");
            std::cout
            << "Nome carteira: ";
            std::cin.ignore();
            std::getline(std::cin , wallet_name);
            Wallet* temp = new Wallet(wallet_name);
            wallet[numWallet].name = temp->name;
            delete temp;
            system("cls");
            std::cout 
            << "======================================================================" << '\n'
            << "Carteira " << wallet[numWallet].name << '\n'
            << '\n'
            << "Chave Privada " << wallet[numWallet].privateKey << '\n'
            << '\n'
            << "Chave Publica " << wallet[numWallet].publicKey << '\n'
            << "======================================================================" << '\n'
            << '\n' << '\n';
            numWallet++;
            system("pause");
        }

    }

    return 0;
}