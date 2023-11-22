#include"blockchain.h"


Blockchain::Blockchain()
{
    Block* block = new Block;
    block->index = 0;
    block->nonce = 0;
    block->status = Invalido;
    block->prevHash = "null";
    
    genesis = actual = block;
    setHash(actual->data);
}

std::string Blockchain::getGenesisTimestamp()
{   
    std::time_t timestamp = genesis->timestamp;
    return (std::asctime(std::localtime(&timestamp)));
}

void Blockchain::setData(const std::string &d)
{
    actual->data = d;
    setHash(actual->data);
    actual->status = Invalido;
}

void Blockchain::setHash(const std::string &d)
{
    actual->hash = sha256(d + std::to_string(actual->nonce));
}

void printBlockchain()
{

}

void Blockchain::mine()
{
    int nonce_ = 0;
    std::string validHash;

    while(true)
    {
        validHash = sha256(actual->data + std::to_string(nonce_));
        std::cout << validHash << '\n';
        int result = validHash.compare(0, 4, difficulty);
        if(result == 0)
        {
            actual->status = Valido;
            setTimestamp();
            break;
        }
        nonce_++;
    }
    actual->nonce = nonce_;
    actual->hash = validHash;
}

void Blockchain::setTimestamp()
{
    actual->timestamp = std::time(0);
}