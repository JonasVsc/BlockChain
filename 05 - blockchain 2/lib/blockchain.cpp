#include"blockchain.h"

std::string transactions_tostring(const std::vector<Transaction>& transactions)
{
    std::string result;
    for (const auto& transaction : transactions) 
    {
        result += transaction.sender + transaction.receiver + std::to_string(transaction.amount);
    }
    return result;
}

Blockchain::Blockchain()
{
    Block* block = new Block;
    block->index = 0;
    std::string genesis_prev(64, '0');
    block->previousHash = genesis_prev;
    block->nonce = 0;
    block->reward = 250;
    block->status = Invalido;
    block->timestamp = 0;
    block->hash = sha256((std::to_string(block->index) + std::to_string(block->nonce) + block->previousHash + transactions_tostring(block->transactions)));

    genesis = atual = block;
}


void Blockchain::mine(const std::string& publKey)
{
    unsigned int nonce = 0;
    std::string validHash;
    std::string blockHeader;
    
    std::cout << "Mining..." << '\n' << '\n';
    while(true)
    {
        blockHeader = (std::to_string(atual->index) + std::to_string(nonce) + atual->previousHash + atual->hash);
        validHash = sha256((blockHeader));
        int result = validHash.compare(0, 4, "0000");
        if(result == 0)
        {
            atual->status = Valido;
            atual->timestamp = std::time(0);
            system("cls");
            std::cout 
            << "======================================================================" << '\n'
            << std::asctime(std::localtime(&atual->timestamp)) << '\n'
            << "Nonce " << nonce << '\n'
            << '\n'
            << "Hash " << validHash << '\n'
            << '\n'
            << "O Nonce encontrado satisfez as condicoes e foi transmitido!" << '\n'
            << '\n'
            << "Um novo bloco foi gerado!" << '\n'
            << '\n'
            << "Foi enviado a recompensa de " << atual->reward << " cryptos para sua carteira" << '\n'
            << '\n'
            << "Chave Publica: " << publKey << '\n'
            << '\n'
            << "======================================================================" << '\n'
            << '\n';
            system("pause");
            break;
        }
        nonce++;
    }
    atual->nonce = nonce;
    atual->hash = validHash;
    newBlock();
    addTransaction(publKey, atual->previous->reward);
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
            recalculateHash();
        }
    }
}

void Blockchain::addTransaction(const std::string& receiver, const Crypto& amount) const
{
    Transaction transaction;

    transaction.sender = "System";
    transaction.receiver = receiver;
    transaction.amount = amount;
    
    atual->transactions.push_back(transaction);
}

void Blockchain::recalculateHash()
{
    atual->hash = sha256((std::to_string(atual->index) + std::to_string(atual->nonce) + atual->previousHash + transactions_tostring(atual->transactions)));
}

void Blockchain::listTransactions(const std::vector<Transaction>& transactions) const
{
    for (const auto& transacao : transactions) {
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


void Blockchain::newBlock()
{
    Block* block = new Block;

    block->index = atual->index + 1;
    block->reward = atual->reward / 2;
    block->nonce = 0;
    block->status = Invalido;
    block->timestamp = 0;
    block->previous = atual;

    atual = block;
    atual->previousHash = atual->previous->hash;
    atual->hash = sha256((std::to_string(atual->index) + std::to_string(atual->nonce) + atual->previousHash));

}

