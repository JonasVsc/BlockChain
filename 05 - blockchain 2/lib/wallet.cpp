#include"wallet.h"

Wallet::Wallet()
{
    generateWalletKeys(privateKey, publicKey);
}

void Wallet::setPublicKey(std::string pk)
{
    publicKey = pk;
}

void Wallet::setPrivateKey(std::string pk)
{
    privateKey = pk;
}

void Wallet::generateWalletKeys(std::string& privKey, std::string& publKey)
{
    // Inicializar a biblioteca OpenSSL
    OpenSSL_add_all_algorithms();
    ERR_load_BIO_strings();

    const char *curve_name = "secp256k1";

    EC_KEY *ec_key = EC_KEY_new_by_curve_name(OBJ_txt2nid(curve_name));

    if (!ec_key) {
        std::cerr << "Erro ao criar a estrutura de contexto da curva elíptica." << std::endl;
    }

    if (!EC_KEY_generate_key(ec_key)) {
        std::cerr << "Erro ao gerar a chave privada." << std::endl;
    }

    const BIGNUM *private_key = EC_KEY_get0_private_key(ec_key);

    const EC_POINT *public_key_point = EC_KEY_get0_public_key(ec_key);

    char *public_key_hex = EC_POINT_point2hex(EC_KEY_get0_group(ec_key), public_key_point, POINT_CONVERSION_UNCOMPRESSED, NULL);

    publKey = public_key_hex;
    privKey = BN_bn2hex(private_key);

    OPENSSL_free(public_key_hex);
    EC_KEY_free(ec_key);

    EVP_cleanup();
    CRYPTO_cleanup_all_ex_data();

}


