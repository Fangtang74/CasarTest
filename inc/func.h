#ifndef FUNC_H
#define FUNC_H

#include <string>
#include <vector>
#include <cryptopp/osrng.h>
#include <cryptopp/rsa.h>
// Function declarations
size_t hashFunction(const std::string &str);
std::string xorFunction(const std::string &a, const std::string &b);
int randomFunction(int min, int max);
std::string randomString(int length);
std::string pufFunction(const std::string &C);
std::vector<int> shuffleFunction(std::vector<int> &nums);
double chebyshevFunction(double x);
std::string aesEncrypt(const std::string &plainText, const CryptoPP::SecByteBlock &key);
std::string aesDecrypt(const std::string &cipherText, const CryptoPP::SecByteBlock &key);
std::string rsaEncrypt(const std::string &plainText, const CryptoPP::RSA::PublicKey &publicKey);
std::string rsaDecrypt(const std::string &cipherText, const CryptoPP::RSA::PrivateKey &privateKey);

#endif // FUNC_H