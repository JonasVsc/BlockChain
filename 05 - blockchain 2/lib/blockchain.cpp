#include"blockchain.h"



Blockchain::Blockchain()
{
    Block* block = new Block;
    block->index = 0;
    block->previousHash = "";

    //hash =  ( blockIndex, merkleRoot, nonce, previousHash)
    genesis = atual = block;
    delete block;
}

//precisa adicionar verificações
void Blockchain::addTransaction()
{
    Transaction transaction;
    std::string sender, receiver;
    Crypto amount;
    char opt;

    system("cls");
    std::cout << "De: ";
    std::cin >> sender;
    std::cout << '\n';
    std::cout << "Para: ";
    std::cin >> receiver;
    std::cout << '\n';
    std::cout << "Quantia: ";
    std::cin >> amount;

    std::cout << "======================================================================" << '\n' << '\n';

    

    transaction.sender = sender;
    transaction.receiver = receiver;
    transaction.amount = amount;
    while(opt != 's' && opt != 'n')
    {
        system("cls");
        std::cout 
        << "De: " << sender << '\n'
        << '\n'
        << "Para: " << receiver << '\n'
        << '\n'
        << "Quantia: " << amount << '\n'
        << '\n' << '\n';
        std::cout 
        << "Confirmar Transacao? S/N" 
        << '\n'
        << '>';
        std::cin >> opt;
        if(opt == 's')
        {
            atual->transactions.push_back(transaction);
        }
    }
}

void Blockchain::listTransactions()
{
    for (const auto& transacao : atual->transactions) {
        std::cout 
        << '\n' 
        << '\n' 
        << "De: " << transacao.sender << '\n'
        << '\n'
        << "Para: " << transacao.receiver << '\n'
        << '\n'
        << "Quantia: " << transacao.amount << '\n'
        << '\n'
        << '\n'
        << "======================================================================" 
        << '\n';
    }
}




