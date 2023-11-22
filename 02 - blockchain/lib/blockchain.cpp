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

void Blockchain::setData(const std::string &d)
{
    Block* temp = new Block;
    selected->data = d;
    selected->hash = sha256(selected->data + std::to_string(selected->nonce) + std::to_string(selected->index) + (selected == genesis ? "" : selected->prev->hash));
    temp = selected;
    while(temp != nullptr)
    {
        temp->hash = sha256(temp->data + std::to_string(temp->nonce) + std::to_string(temp->index) + (temp == genesis ? "" : temp->prev->hash));
        temp->status = Invalido;
        temp = temp->next;
    }
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
        << "===========================================================================" << '\n'
        << "Status: " << (temp->status == Valido ? "Minerado" : "Nao Minerado") << '\n'
        << "Nonce: " << temp->nonce << " " << "\n\n"
        << "Data: " << temp->data << "\n\n"
        << "Hash: " << temp->hash << '\n'
        << "PrevHash: " << (temp != genesis ? temp->prev->hash : "000000000000") << "\n\n"
        << (temp->status == Valido ? std::asctime(std::localtime(&temp->timestamp)) : "") << '\n' // CONDIÇAO
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
    actual->next = block;
    actual = block;
}

void Blockchain::mine()
{
    int nonce_ = 0;
    std::string validHash;

    while(true)
    {
        selected->timestamp = std::time(0);
        validHash = sha256(selected->data + std::to_string(nonce_) + std::to_string(selected->index) + (selected != genesis ? selected->prev->hash : "") + std::to_string(selected->timestamp));
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
}

void Blockchain::setTimestamp()
{
    actual->timestamp = std::time(0);
}

void Blockchain::selectBlock(int& index)
{
    Block* temp = new Block;
    temp = genesis;

    if(index > actual->index)
    {
        std::cout << "Nao existe o bloco indicado\n";
        return;
    }

    while(true)
    {
        if(index == temp->index)
        {
            selected = temp;
            break;
        }
        temp = temp->next;
    }
}

void Blockchain::printSelected()
{
        std::cout
        << "# [" << selected->index << "] " << '\n'
        << "===========================================================================" << '\n'
        << "Status: " << (selected->status == Valido ? "Minerado" : "Nao Minerado") << '\n'
        << "Nonce: " << selected->nonce << " " << "\n\n"
        << "Data: " << selected->data << "\n\n"
        << "Hash: " << selected->hash << '\n'
        << "PrevHash: " << (selected != genesis ? selected->prev->hash : "000000000000") << "\n\n"
        << (selected->status == Valido ? std::asctime(std::localtime(&selected->timestamp)) : "") << '\n'
        << "===========================================================================" << "\n\n";
}


