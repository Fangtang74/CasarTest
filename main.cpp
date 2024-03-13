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
    std::ofstream file1("uavTime.csv");
    file1 << "Nums,feng,kar,pu,our\n";
    for (int i = 10; i <= 50; i += 10)
    {
        file1 << i << "," << fengSchemeUav(i) << "," << karSchemeUav(i) << "," << puSchemeUav(i) << "," << ourSchemeUav(i) << "\n";
    }
    file1.close();
    std::ofstream file2("gsTime.csv");
    file2 << "Nums,feng,kar,pu,our\n";
    for (int i = 10; i <= 50; i += 10)
    {
        file2 << i << "," << fengSchemeGs(i) << "," << karSchemeGs(i) << "," << puSchemeGs(i) << "," << ourSchemeGs(i) << "\n";
    }
    file2.close();
    getFuncTime();
    return 0;
}