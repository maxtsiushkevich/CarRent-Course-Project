#ifndef CARRENT_CARINUSAGE_H
#define CARRENT_CARINUSAGE_H
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

struct CarInUsage
{
private:
    int lastDay;
    int carID;
public:
    CarInUsage() = default;
    CarInUsage(int, int);
    ~CarInUsage() = default;
    void WriteInFile();
    void RefreshFile();

    void GetCarsInUsage(vector<int>&);
};

#endif
