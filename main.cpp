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
    for (int i = 1; i <= 50; i += 1)
    {
        file1 << i << "," << fengSchemeUav(i) << "," << karSchemeUav(i) << "," << puSchemeUav(i) << "," << ourSchemeUav(i) << "\n";
    }
    file1.close();
    std::ofstream file2("totalTime.csv");
    file2 << "Nums,feng,kar,pu,our\n";
    for (int i = 1; i <= 50; i += 1)
    {
        file2 << i << "," << fengSchemeGs(i) + fengSchemeUav(i) << "," << karSchemeGs(i) + karSchemeUav(i) << "," << puSchemeGs(i) + puSchemeUav(i) << "," << ourSchemeGs(i) + ourSchemeUav(i) << "\n";
    }
    file2.close();
    // getFuncTime();
    return 0;
}