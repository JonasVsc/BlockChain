#include"hash.h"

std::string sha256(const std::string& input);


int main() {
    char option;
    std::string data;
    
    while(true)
    {
        std::string hashed = sha256(data);

        std::cout
        << "==========================================\n\n"
        << "STATUS:" << "need mining" << "\n\n"
        << "Bloco: " << "Index" << "\n\n"
        << "Nonce:" << "number_nonce" << "\n\n"
        << "Dados: " << data << "\n\n"
        << "Hash: " << hashed << "\n\n"
        << "==========================================\n\n";

        std::cout
        << "\n\nOptions:\n"
        << "[0] - Sair\n"
        << "[1] - Inserir dados\n"
        << "[2] - Minerar\n";
        std::cin >> option;
        std::cout << "\n\n";

        if(option == '0')
        {
            return 0;
        }
        if(option == '1')
        {
            std::cout << "Data: ";
            std::cin >> data;
            std::string hashed = sha256(data);
            std::cout << "\n\n";
        }
        if(option == '2')
        {

        }

        system("cls");
    }


    
    system("pause");
    return 0;
}
