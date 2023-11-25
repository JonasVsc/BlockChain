#include <iostream>
#include <openssl/evp.h>
#include <iomanip>
#include <openssl/ec.h>
#include <openssl/obj_mac.h>
#include <openssl/rand.h>
#include <openssl/bio.h>
#include <openssl/pem.h>


std::string sha256(const std::string& input);



