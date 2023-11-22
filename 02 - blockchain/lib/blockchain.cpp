#include"blockchain.h"


Blockchain::Blockchain()
{
    Block* block = new Block;
    block->index = 0;
    block->nonce = 0;
    block->status = Invalido;
    block->timestamp = std::time(0);
    
    genesis = actual = block;
}

std::string Blockchain::getGenesisTimestamp()
{   
    std::time_t timestamp = genesis->timestamp;
    return (std::asctime(std::localtime(&timestamp)));
}

void Blockchain::setData(const std::string &d)
{
    actual->data = d;
}