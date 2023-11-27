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
    std::string wallet_name, sender, receiver;
    int numWallet = 0, amount;
    int index = 0, search_block_index = 0;
    char opt;

    while(true)
    {
        system("cls");
        
        std::cout
        << "======================================================================" << '\n'
        << "Bloco Atual [" << blockchain.atual->index << ']' << '\n'
        << '\n'
        << "Hash " << blockchain.atual->hash << '\n'
        << '\n'
        << "Prev " << blockchain.atual->previousHash << '\n'
        << '\n'
        << "Nonce " << blockchain.atual->nonce << '\n'
        << "======================================================================" << '\n'
        << '\n'
        << "[0] Detalhes de um bloco" << '\n'
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
            std::cout
            << "======================================================================" << '\n'
            << "Numero de Blocos " << blockchain.atual->index + 1 << '\n'
            << "======================================================================" << '\n'
            << '\n'
            << "Index Bloco: ";
            std::cin >> search_block_index;

            system("cls");

            Block* temp = new Block;
            temp = blockchain.atual;


            while(temp->index > search_block_index && search_block_index >= 0)
            {
                temp = temp->previous;
            }

            if(temp->index != search_block_index)
            {
                std::cout << "Bloco nao existe" << '\n';
                system("pause");
                continue;
            }


            system("cls");
            std::cout
            << "======================================================================" << '\n'
            << (temp->status ? (std::asctime(std::localtime(&temp->timestamp))) : "") << '\n' 
            << "Bloco [" << temp->index << "]" << '\n'
            << '\n'
            << "Nonce " << temp->nonce << '\n'
            << '\n'
            << "Hash " << temp->hash << '\n'
            << '\n'
            << "Prev " << temp->previousHash << '\n'
            << '\n'
            << "Recompensa " << temp->reward << '\n'
            << '\n'
            << "Transacoes " << temp->transactions.size() << '\n'
            << '\n'
            << "======================================================================" << '\n'
            << '\n'
            << "[0] Listar Transacoes" << '\n'
            << '\n'
            << "[1] Voltar" << '\n'
            << '\n'
            << "----------------------------------------------------------------------" << '\n'
            << '\n'
            << '>';
            std::cin >> opt;

            if(opt == '0')
            {
                system("cls");
                blockchain.listTransactions(temp->transactions);
                system("pause");

            }
            if(opt == '1')
            {
                continue;
            }
        }

        if(opt == '1')
        {
            system("cls");
            std::cout << "Hash Transacao: ";
            std::cin >> sender;

            system("cls");
            system("pause");
        }

        if(opt == '2')
        {
            blockchain.addTransaction();
        }

        if(opt == '3')
        {
            system("cls");
            std::cout 
            << "======================================================================" << '\n'
            << "Insira uma chave valida" << '\n'
            << "======================================================================" << '\n'
            << '\n'
            << "Chave Publica: ";
            std::cin >> sender;

            system("cls");
            blockchain.mine(sender);
        }

        if(opt == '4')
        {
            int i = 0;
            system("cls");

            while(!(wallet[i].name.empty()))
            {
                std::cout
                << '\n' << '\n'
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
            << '\n' << '\n'
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