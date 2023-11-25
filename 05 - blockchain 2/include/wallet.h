#include <iostream>
#include <openssl/evp.h>
#include <iomanip>
#include <openssl/ec.h>
#include <openssl/obj_mac.h>
#include <openssl/rand.h>
#include <openssl/bio.h>
#include <openssl/pem.h>


class Wallet {
    public:
        Wallet();

        void setPublicKey(std::string pk);
        void setPrivateKey(std::string pk);
        void generateWalletKeys(std::string& privKey, std::string& publKey);


        std::string publicKey;
        std::string privateKey;
    private:

};