#include "func.h"
#include <iostream>
#include <string>
#include <functional>
#include <random>
#include <cmath>
#include <algorithm>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/rsa.h>
#include <cryptopp/osrng.h>
#include <cryptopp/base64.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <stdio.h>
#include <string.h>

// 编译命令
// g++ -I/usr/local/include/cryptopp -o run main.cc -L/usr/local/lib/libcryptopp.a -lcryptopp

// 哈希函数
size_t hashFunction(const std::string &str)
{
    return std::hash<std::string>{}(str);
}
// 异或函数
std::string xorFunction(const std::string &a, const std::string &b)
{
    std::string result;
    std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(result), [](char a, char b)
                   { return a ^ b; });
    return result;
}
// 随机数生成函数
int randomFunction(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}
// 随机字符串生成函数
std::string randomString(int length)
{
    static const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    std::string random_string;
    for (int i = 0; i < length; ++i)
    {
        random_string += characters[distribution(generator)];
    }

    return random_string;
}
// PUF函数
std::string pufFunction(const std::string &C)
{
    size_t hashValue = hashFunction(C);
    int randomValue = randomFunction(0, 255);
    std::string R = xorFunction(std::to_string(hashValue), std::to_string(randomValue));
    return R;
}
// 洗牌函数
std::vector<int> shuffleFunction(std::vector<int> &nums)
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(nums.begin(), nums.end(), g);
    return nums;
}
// 切比雪夫函数
double chebyshevFunction(double x)
{
    return cos(acos(x) * 2.0);
}
//  aes加密
std::string aesEncrypt(const std::string &plainText, const CryptoPP::SecByteBlock &key)
{
    std::string cipherText;
    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::ECB_Mode_ExternalCipher::Encryption ecbEncryption(aesEncryption);

    CryptoPP::StreamTransformationFilter stfEncryptor(ecbEncryption, new CryptoPP::StringSink(cipherText));
    stfEncryptor.Put(reinterpret_cast<const unsigned char *>(plainText.c_str()), plainText.length() + 1);
    stfEncryptor.MessageEnd();

    return cipherText;
}
//  aes解密
std::string aesDecrypt(const std::string &cipherText, const CryptoPP::SecByteBlock &key)
{
    std::string decryptedText;
    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::ECB_Mode_ExternalCipher::Decryption ecbDecryption(aesDecryption);

    CryptoPP::StreamTransformationFilter stfDecryptor(ecbDecryption, new CryptoPP::StringSink(decryptedText));
    stfDecryptor.Put(reinterpret_cast<const unsigned char *>(cipherText.c_str()), cipherText.size());
    stfDecryptor.MessageEnd();

    return decryptedText;
}
// rsa加密
std::string rsaEncrypt(const std::string &plainText, const CryptoPP::RSA::PublicKey &publicKey)
{
    std::string cipherText;
    CryptoPP::AutoSeededRandomPool rng;

    CryptoPP::RSAES_OAEP_SHA_Encryptor encryptor(publicKey);

    CryptoPP::StringSource ss1(plainText, true,
                               new CryptoPP::PK_EncryptorFilter(rng, encryptor,
                                                                new CryptoPP::StringSink(cipherText)) // PK_EncryptorFilter
    );                                                                                                // StringSource

    return cipherText;
}
// rsa解密
std::string rsaDecrypt(const std::string &cipherText, const CryptoPP::RSA::PrivateKey &privateKey)
{
    std::string decryptedText;
    CryptoPP::AutoSeededRandomPool rng;

    CryptoPP::RSAES_OAEP_SHA_Decryptor decryptor(privateKey);

    CryptoPP::StringSource ss2(cipherText, true,
                               new CryptoPP::PK_DecryptorFilter(rng, decryptor,
                                                                new CryptoPP::StringSink(decryptedText)) // PK_DecryptorFilter
    );                                                                                                   // StringSource

    return decryptedText;
}
