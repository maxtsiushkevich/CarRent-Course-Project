#include "CarInUsage.h"
#include <fstream>
#include <iostream>

CarInUsage :: CarInUsage(int lastDay, int carID) {
    this->lastDay = lastDay;
    this->carID = carID;
}

void CarInUsage :: WriteInFile() {
    ofstream file;
    file.open("/Users/max/Desktop/CarRent/Files/CarInUsage.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char *) this, sizeof(CarInUsage));
    file.close();
    this->RefreshFile();
}

void CarInUsage :: RefreshFile() {
    int nowDay;
    time_t seconds = time(NULL);
    tm *currentTime = localtime(&seconds);
    int a = (14 - currentTime->tm_mon + 1) / 12;
    int y = currentTime->tm_year + 1900 + 4800 - a;
    int m = currentTime->tm_mon + 1 + 12 * a - 3;
    nowDay = currentTime->tm_mday + ((153 * m + 2) / 5) + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    ifstream file1; // для чтения
    ofstream file2; // для записи
    file1.open("/Users/max/Desktop/CarRent/Files/CarInUsage.bin", ios::binary);
    if (!file1.is_open())
        cout << "Error";
    file2.open("/Users/max/Desktop/CarRent/Files/tmp.bin", ios::binary | ios::app);
    while (file1.read((char *) this, sizeof(CarInUsage))) {
        if (this->lastDay >= nowDay)
            file2.write((char *) this, sizeof(CarInUsage));
        else
            continue;
    }
    file1.close();
    remove("/Users/max/Desktop/CarRent/Files/CarInUsage.bin");
    file2.close();
    rename("/Users/max/Desktop/CarRent/Files/tmp.bin", "/Users/max/Desktop/CarRent/Files/CarInUsage.bin");
}

void CarInUsage :: GetCarsInUsage(vector<int> &carIdInUsage) {
    this->RefreshFile();
    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/CarInUsage.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while (file.read((char *) this, sizeof(CarInUsage)))
        carIdInUsage.push_back(this->carID);
    file.close();
}