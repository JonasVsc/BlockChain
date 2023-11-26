#include"blockchain.h"


Blockchain::Blockchain()
{
    Block* block = new Block;
    block->index = 0;
    block->previousHash = "0000000000000000000000000000000000000000000000000000000000000000";
    block->nonce = 0;

    block->hash = sha256((std::to_string(block->index) + std::to_string(block->nonce) + block->previousHash));

    //hash =  ( blockIndex, merkleRoot, nonce, previousHash)
    genesis = atual = block;
}


//Há um bug que bad_alloc, não sei o por que, identificar dps
void Blockchain::mine(std::string& publKey)
{
    unsigned int nonce = 0;
    std::string validHash;
    std::string blockHeader;
    
    std::cout << "Mining..." << '\n' << '\n';
    while(true)
    {
        blockHeader = (std::to_string(atual->index) + std::to_string(nonce) + atual->previousHash + atual->hash);
        validHash = sha256((blockHeader + atual->merkleRoot));
        int result = validHash.compare(0, 4, "0000");
        if(result == 0)
        {
            std::cout << validHash << '\n';
            system("pause");
            break;
        }
        nonce++;
    }
    atual->nonce = nonce;
    atual->hash = validHash;

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




