#include<string>
#include"block.h"
#include"hash.h"


Block::Block()
    : index(0), nonce(0), data(""), status(0)
{

}

void Block::mine()
{
    int nonce_ = 0;
    std::string validHash;

    while(true)
    {
        validHash = sha256(data + std::to_string(nonce_));
        std::cout << validHash << '\n';
        int result = validHash.compare(0, 4, difficulty);
        if(result == 0)
        {
            setStatus(1);
            break;
        }
        nonce_++;
    }
    nonce = nonce_;
    hash = validHash;
    
}

int Block::getIndex()
{
    return index;
}

int Block::getNonce()
{
    return nonce;
}

std::string Block::getData()
{
    return data;
}

std::string Block::getHash()
{
    return hash;
}

int Block::getStatus()
{
    return status;
}

void Block::setData(const std::string &data_)
{
    data = data_;
    setHash(sha256(data) + std::to_string(nonce));
    setStatus(0);
}

void Block::setHash(const std::string &data_)
{
    hash = sha256(data_);
}

void Block::setStatus(int st)
{
    status = st;
}


