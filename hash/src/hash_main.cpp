#include <iostream>
#include <iomanip>
#include <openssl/evp.h>

std::string sha256(const std::string& input) {
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;

    OpenSSL_add_all_digests();
    md = EVP_get_digestbyname("sha256");

    if (!md) {
        std::cerr << "Erro ao obter o algoritmo SHA-256" << std::endl;
        return "";
    }

    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, nullptr);
    EVP_DigestUpdate(mdctx, input.c_str(), input.length());
    EVP_DigestFinal_ex(mdctx, hash, &hash_len);
    EVP_MD_CTX_free(mdctx);

    // Convertendo o hash para uma string hexadecimal
    std::stringstream ss;
    for (unsigned int i = 0; i < hash_len; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return ss.str();
}

int main() {
    std::string input;
    std::cout << "Digite a string a ser transformada em hash: ";
    std::getline(std::cin, input);

    std::string hashed = sha256(input);

    std::cout << "Hash SHA-256: " << hashed << std::endl;
    system("pause");
    return 0;
}
