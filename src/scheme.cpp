#include <iostream>
#include "func.h"
#include <random>
#include <fstream>
#include <inttypes.h>
#include "NIST/rng.h"
extern "C"
{
#include "FE.h"
}

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
    uint8_t seed_a[32];
    int8_t c[PARAMS_M] = {0};
    uint8_t r1[PARAMS_R_BYTES] = {0};
    uint8_t r2[PARAMS_R_BYTES] = {0};
    int8_t w[PARAMS_N] = {0};
    int8_t delta[PARAMS_N] = {0};
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
        Gen(seed_a, c, r1, w);
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
    }
    auto end = std::chrono::steady_clock::now();
    double dr_ms = std::chrono::duration<double, std::milli>(end - start).count();
    return dr_ms;
}

double fengSchemeGs(int num)
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

double karSchemeGs(int num)
{
    std::string content = "Hello, World!";
    int cnt = 0;
    uint8_t seed_a[32];
    int8_t c[PARAMS_M] = {0};
    uint8_t r1[PARAMS_R_BYTES] = {0};
    uint8_t r2[PARAMS_R_BYTES] = {0};
    int8_t w[PARAMS_N] = {0};
    int8_t delta[PARAMS_N] = {0};
    Gen(seed_a, c, r1, w);
    string res = pufFunction(content);
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < num; i++)
    {
        size_t hashContent = hashFunction(content);
        hashContent = hashFunction(content);
        string rs = randomString(160);
        hashContent = hashFunction(rs);
        hashContent = hashFunction(rs);
        for (int i = 0; i < 8; i++)
        {
            string xorRes = xorFunction(rs, res);
        }
        Rep(r2, seed_a, c, w);
    }
    auto end = std::chrono::steady_clock::now();
    double dr_ms = std::chrono::duration<double, std::milli>(end - start).count();
    return dr_ms;
}

double puSchemeGs(int num)
{
    std::string content = "Hello, World!";
    CryptoPP::AutoSeededRandomPool rng;
    CryptoPP::SecByteBlock key(0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
    rng.GenerateBlock(key, key.size());
    auto vec = randomVector(200);
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < num; i++)
    {
        size_t hashContent = hashFunction(to_string(hashContent));
        for (int i = 0; i < 6; i++)
        {
            hashContent = hashFunction(to_string(hashContent));
        }
        string rs = randomString(160);
        vec = shuffleFunction(vec);
        vec = shuffleFunction(vec);
        vec = shuffleFunction(vec);
        vec = shuffleFunction(vec);
        vec = shuffleFunction(vec);
        string res = pufFunction(rs);
        string xorRes = xorFunction(rs, res);
        std::string encryptedContent2 = aesEncrypt(content, key);
    }
    auto end = std::chrono::steady_clock::now();
    double dr_ms = std::chrono::duration<double, std::milli>(end - start).count();
    return dr_ms;
}

double ourSchemeGs(int num)
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
        hashContent = hashFunction(rs);
        hashContent = hashFunction(rs);
        hashContent = hashFunction(rs);
        string xorRes = xorFunction(rs, content);
        auto chebyshevRes = chebyshevFunction(dob);
        std::string encryptedContent2 = aesEncrypt(content, key);
        std::string decryptedContent2 = aesDecrypt(encryptedContent2, key);
    }
    auto end = std::chrono::steady_clock::now();
    double dr_ms = std::chrono::duration<double, std::milli>(end - start).count();
    return dr_ms;
}

void getFuncTime()
{
    vector<double> result;
    std::string content = "Hello, World!";
    auto dob = randomDouble();
    CryptoPP::AutoSeededRandomPool rng;
    CryptoPP::SecByteBlock key(0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
    rng.GenerateBlock(key, key.size());
    CryptoPP::RSA::PrivateKey privateKey;
    privateKey.GenerateRandomWithKeySize(rng, 3072);
    CryptoPP::RSA::PublicKey publicKey(privateKey);
    int cnt = 0;
    uint8_t seed_a[32];
    int8_t c[PARAMS_M] = {0};
    uint8_t r1[PARAMS_R_BYTES] = {0};
    uint8_t r2[PARAMS_R_BYTES] = {0};
    int8_t w[PARAMS_N] = {0};
    int8_t delta[PARAMS_N] = {0};
    string rs = randomString(160);
    auto vec = randomVector(200);
    double sum = 0;
    // 分别进行函数运算1000次并且计算平均时间   计算顺序为哈希，随机数，puf，洗牌，切比雪夫，rsa，aes, FE
    for (int i = 0; i < 1000; i++)
    {
        auto start = std::chrono::steady_clock::now();
        size_t hashContent = hashFunction(content);
        auto end = std::chrono::steady_clock::now();
        sum += std::chrono::duration<double, std::milli>(end - start).count();
    }
    result.push_back(sum / 1000);
    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        auto start = std::chrono::steady_clock::now();
        string rs = randomString(160);
        auto end = std::chrono::steady_clock::now();
        sum += std::chrono::duration<double, std::milli>(end - start).count();
    }
    result.push_back(sum / 1000);
    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        auto start = std::chrono::steady_clock::now();
        string res = pufFunction(rs);
        auto end = std::chrono::steady_clock::now();
        sum += std::chrono::duration<double, std::milli>(end - start).count();
    }
    result.push_back(sum / 1000);
    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        auto start = std::chrono::steady_clock::now();
        vec = shuffleFunction(vec);
        auto end = std::chrono::steady_clock::now();
        sum += std::chrono::duration<double, std::milli>(end - start).count();
    }
    result.push_back(sum / 1000);
    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        auto start = std::chrono::steady_clock::now();
        auto chebyshevRes = chebyshevFunction(dob);
        auto end = std::chrono::steady_clock::now();
        sum += std::chrono::duration<double, std::milli>(end - start).count();
    }
    result.push_back(sum / 1000);
    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        auto start = std::chrono::steady_clock::now();
        std::string encryptedContent = rsaEncrypt(content, publicKey);
        std::string decryptedContent = rsaDecrypt(encryptedContent, privateKey);
        auto end = std::chrono::steady_clock::now();
        sum += std::chrono::duration<double, std::milli>(end - start).count();
    }
    result.push_back(sum / 1000);
    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        auto start = std::chrono::steady_clock::now();
        std::string encryptedContent2 = aesEncrypt(content, key);
        std::string decryptedContent2 = aesDecrypt(encryptedContent2, key);
        auto end = std::chrono::steady_clock::now();
        sum += std::chrono::duration<double, std::milli>(end - start).count();
    }
    result.push_back(sum / 1000);
    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        auto start = std::chrono::steady_clock::now();
        Gen(seed_a, c, r1, w);
        auto end = std::chrono::steady_clock::now();
        sum += std::chrono::duration<double, std::milli>(end - start).count();
    }
    result.push_back(sum / 1000);
    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        auto start = std::chrono::steady_clock::now();
        Rep(r2, seed_a, c, w);
        auto end = std::chrono::steady_clock::now();
        sum += std::chrono::duration<double, std::milli>(end - start).count();
    }
    result.push_back(sum / 1000);
    std::ofstream file("funcTime.csv");
    file << "hash,random,puf,shuffle,chebyshev,rsa,aes,FE_Gen,FE_Rep\n";
    for (const auto &val : result)
    {
        file << val << ",";
    }
    file.close();
}