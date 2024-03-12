#include <iostream>
#include "func.h"
#include <random>

using namespace std;

std::vector<int> randomVector(int size)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, 1000); // Generates random ints between 0 and 100

    std::vector<int> nums;
    for (int i = 0; i < size; ++i)
    {
        nums.push_back(distribution(generator));
    }

    return nums;
}

double randomDouble()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<> distribution(0.0, 1.0); // Generates random doubles between 0.0 and 1.0

    return distribution(generator);
}

double fengSchemeUav(int num)
{
    // RSA的公私钥生成
    CryptoPP::AutoSeededRandomPool rng;
    CryptoPP::RSA::PrivateKey privateKey;
    privateKey.GenerateRandomWithKeySize(rng, 3072);
    std::string content = "Hello, World!";
    CryptoPP::RSA::PublicKey publicKey(privateKey);
    // AES密钥生成
    CryptoPP::SecByteBlock key(0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
    rng.GenerateBlock(key, key.size());

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < num; i++)
    {
        std::string encryptedContent = rsaEncrypt(content, publicKey);
        std::string decryptedContent = rsaDecrypt(encryptedContent, privateKey);
        std::string encryptedContent2 = aesEncrypt(content, key);
        std::string decryptedContent2 = aesDecrypt(encryptedContent2, key);
        size_t hashContent = hashFunction(content);
        hashContent = hashFunction(content);
    }
    auto end = std::chrono::steady_clock::now();
    double dr_ms = std::chrono::duration<double, std::milli>(end - start).count();
    return dr_ms;
}

double karSchemeUav(int num)
{
    std::string content = "Hello, World!";
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < num; i++)
    {
        size_t hashContent = hashFunction(content);
        hashContent = hashFunction(content);
        string rs = randomString(160);
        hashContent = hashFunction(rs);
        rs = randomString(160);
        hashContent = hashFunction(rs);
        string res = pufFunction(rs);
        res = pufFunction(rs);
        for (int i = 0; i < 8; i++)
        {
            string xorRes = xorFunction(rs, res);
        }
        FE();
    }
    auto end = std::chrono::steady_clock::now();
    double dr_ms = std::chrono::duration<double, std::milli>(end - start).count();
    return dr_ms;
}

double puSchemeUav(int num)
{
    std::string content = "Hello, World!";
    CryptoPP::AutoSeededRandomPool rng;
    CryptoPP::SecByteBlock key(0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
    rng.GenerateBlock(key, key.size());
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < num; i++)
    {
        size_t hashContent = hashFunction(to_string(hashContent));
        for (int i = 0; i < 5; i++)
        {
            hashContent = hashFunction(to_string(hashContent));
        }
        string rs = randomString(160);
        rs = randomString(160);
        rs = randomString(160);
        auto vec = randomVector(200);
        vec = shuffleFunction(vec);
        vec = shuffleFunction(vec);
        vec = shuffleFunction(vec);
        vec = shuffleFunction(vec);
        string res = pufFunction(rs);
        string xorRes = xorFunction(rs, res);
        std::string encryptedContent2 = aesEncrypt(content, key);
        std::string decryptedContent2 = aesDecrypt(encryptedContent2, key);
        encryptedContent2 = aesEncrypt(content, key);
        decryptedContent2 = aesDecrypt(encryptedContent2, key);
    }
    auto end = std::chrono::steady_clock::now();
    double dr_ms = std::chrono::duration<double, std::milli>(end - start).count();
    return dr_ms;
}

double ourSchemeUav(int num)
{
    std::string content = "Hello, World!";
    auto dob = randomDouble();
    CryptoPP::AutoSeededRandomPool rng;
    CryptoPP::SecByteBlock key(0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
    rng.GenerateBlock(key, key.size());
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < num; i++)
    {
        size_t hashContent = hashFunction(content);
        hashContent = hashFunction(content);
        string rs = randomString(160);
        hashContent = hashFunction(rs);
        rs = randomString(160);
        hashContent = hashFunction(rs);
        hashContent = hashFunction(rs);
        hashContent = hashFunction(rs);
        string res = pufFunction(rs);
        res = pufFunction(rs);
        string xorRes = xorFunction(rs, res);
        auto chebyshevRes = chebyshevFunction(dob);
        std::string encryptedContent2 = aesEncrypt(content, key);
        std::string decryptedContent2 = aesDecrypt(encryptedContent2, key);
    }
    auto end = std::chrono::steady_clock::now();
    double dr_ms = std::chrono::duration<double, std::milli>(end - start).count();
    return dr_ms;
}