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

void Blockchain::addTransaction(Transaction& transaction)
{
    atual->transactions.push_back(transaction);
}

void Blockchain::listTransactions()
{
    for (const auto& transacao : atual->transactions) {
        std::cout 
        << "De: " << transacao.sender << '\n'
        << '\n'
        << "Para: " << transacao.receiver << '\n'
        << '\n'
        << "Quantia: " << transacao.amount << '\n'
        << "======================================================================" << '\n'
        << '\n' << '\n';
    }
}




