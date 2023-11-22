#include"blockchain.h"


Blockchain::Blockchain()
{
    Block* block = new Block;
    block->index = 0;
    block->nonce = 0;
    block->status = Invalido;
    block->data = "";
    block->prevHash = "null";
    block->link = nullptr;
    
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

void Blockchain::printBlockchain()
{
    Block* temp = new Block;
    temp = genesis;
    while(temp != nullptr)
    {
        std::cout
        << "# [" << temp->index << "] " << "\n\n"
        << "Nonce " << temp->nonce << " " << '\n'
        << "Data: " << temp->data << "\n\n"
        << "Hash: " << temp->hash << '\n'
        << "PrevHash: " << temp->prevHash << "\n\n"
        << "===========================================================================" << "\n\n";
        temp = temp->link;
    }
    delete temp;

}

void Blockchain::newBlock()
{
    Block* block = new Block;
    block->index = actual->index + 1;
    block->nonce = 0;
    block->status = Invalido;
    block->data = "";
    block->link = nullptr;
    block->prevHash = actual->hash;
    actual->link = block;
    actual = block;
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

    newBlock();
}

void Blockchain::setTimestamp()
{
    actual->timestamp = std::time(0);
}

