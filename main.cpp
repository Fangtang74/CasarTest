#include <iostream>
#include <cstdlib>
#include "scheme.h"
#include <fstream>
#include <vector>

/*
1. 安装加密库
sudo apt-get install libcrypto++-dev libcrypto++-doc libcrypto++-utils
2. 编译命令
g++ -I/usr/local/include/cryptopp -o run main.cc -L/usr/local/lib/libcryptopp.a -lcryptopp
*/

int main()
{
    std::ofstream file("uavTime.csv");
    file << "Nums,feng,kar,pu,our\n";
    for (int i = 10; i <= 50; i += 10)
    {
        file << i << "," << fengSchemeUav(i) << "," << karSchemeUav(i) << "," << puSchemeUav(i) << "," << ourSchemeUav(i) << "\n";
    }
    file.close();
    return 0;
}