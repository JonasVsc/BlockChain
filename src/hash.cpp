#include <iostream>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <iomanip>
#include <sstream>

int main() {
    // Número que você deseja encriptar (representado como uma string)
    std::string numberToHash = "12345";

    EVP_MD_CTX *mdctx;
    const EVP_MD *md = EVP_sha256(); // Use a função de hash SHA-256

    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, numberToHash.c_str(), numberToHash.size());

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;
    EVP_DigestFinal_ex(mdctx, hash, &hash_len);
    EVP_MD_CTX_free(mdctx);

    // Converter o resultado hash em uma string hexadecimal
    std::stringstream ss;
    for (unsigned int i = 0; i < hash_len; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    std::string hashStr = ss.str();

    // Imprimir o resultado
    std::cout << "Número original: " << numberToHash << std::endl;
    std::cout << "SHA-256 hash: " << hashStr << std::endl;
    system("pause");
    return 0;
}
