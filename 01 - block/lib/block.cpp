#include"block.h"
#include"hash.h"


Block::Block()
    : index(0), nonce(0), data("")
{

}

void Block::mine()
{

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

std::string Block::getStatus()
{
    return "Not Mined / Invalid";
}

void Block::setData(const std::string &data_)
{
    data = data_;
    setHash(sha256(data));
}

void Block::setHash(const std::string &data_)
{
    hash = sha256(data_);
}


