#include"blockchain.h"


Blockchain::Blockchain()
{
    Block* block = new Block;
    block->index = 0;
    block->nonce = 0;
    block->status = Invalido;
    block->data = "";
    block->next = nullptr;
    block->prev = nullptr;
    block->hash = sha256(block->data + std::to_string(block->nonce) + std::to_string(block->index));
    
    genesis = actual = selected = block;
}

std::string Blockchain::getGenesisTimestamp()
{   
    std::time_t timestamp = genesis->timestamp;
    return (std::asctime(std::localtime(&timestamp)));
}

void Blockchain::setData(const std::string &d)
{
    selected->data = d;
    selected->hash = sha256(selected->data + std::to_string(selected->nonce));
    selected->status = Invalido;
}

void Blockchain::printBlockchain()
{
    Block* temp = new Block;
    temp = genesis;
    while(temp != nullptr)
    {
        std::cout
        << "# [" << temp->index << "] " << '\n'
        << "Nonce " << temp->nonce << " " << "\n\n"
        << "Data: " << temp->data << "\n\n"
        << "Hash: " << temp->hash << '\n'
        << "PrevHash: " << (temp != genesis ? temp->prev->hash : "000000000000") << "\n\n"
        << "===========================================================================" << "\n\n";
        temp = temp->next;
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
    block->next = nullptr;
    block->prev = actual;
    block->hash = sha256(block->data + std::to_string(block->nonce) + std::to_string(block->index) + block->prev->hash);
    block->prevHash = block->prev->hash;
    actual->next = block;
    actual = block;
}

void Blockchain::mine()
{
    int nonce_ = 0;
    std::string validHash;

    while(true)
    {
        validHash = sha256(selected->data + std::to_string(nonce_) + std::to_string(selected->index) + (selected != genesis ? selected->prev->hash : ""));
        std::cout << validHash << '\n';
        int result = validHash.compare(0, 4, difficulty);
        if(result == 0)
        {
            selected->status = Valido;
            setTimestamp();
            break;
        }
        nonce_++;
    }
    selected->nonce = nonce_;
    selected->hash = validHash;

    if(selected == actual)
    {
        newBlock();
    }
}

void Blockchain::setTimestamp()
{
    actual->timestamp = std::time(0);
}

