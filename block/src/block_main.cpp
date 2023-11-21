#include <iostream>
#include <iomanip>
#include <openssl/evp.h>

std::string sha256(const std::string& input);


int main() {
    char option;
    
    while(true)
    {

    }
    std::string input;
    std::cout << "Digite a string a ser transformada em hash: ";
    std::getline(std::cin, input);

    std::string hashed = sha256(input);

    std::cout << "Hash SHA-256: " << hashed << std::endl;
    system("pause");
    return 0;
}
