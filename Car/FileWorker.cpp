#include "FileWorker.h"
#include <fstream>
#include <iostream>

void FileWorker :: WriteInFile (OilCar car)
{
    ofstream file("/Users/max/Desktop/CarRent/Files/OilCar.bin", ios::binary | ios::app);
    //ofstream file("/Users/max/Desktop/CarRent/Files/OilCar.txt", ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&car, sizeof(OilCar));
    file.close();
}

void FileWorker :: WriteInFile (DieselCar car)
{
    ofstream file("/Users/max/Desktop/CarRent/Files/DieselCar.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&car, sizeof(DieselCar));
    file.close();
}

void FileWorker :: WriteInFile (PetrolCar car)
{
    ofstream file("/Users/max/Desktop/CarRent/Files/PetrolCar.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&car, sizeof(PetrolCar));
    file.close();
}

void FileWorker :: WriteInFile (ElectricCar car)
{
    ofstream file("/Users/max/Desktop/CarRent/Files/ElectricCar.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&car, sizeof(ElectricCar));
    file.close();
}

void FileWorker :: WriteInFile (HybridCar car)
{
    ofstream file("/Users/max/Desktop/CarRent/Files/ElectricCar.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&car, sizeof(HybridCar));
    file.close();
}

void FileWorker :: ReadFromFile(OilCar car)
{
    ifstream file("/Users/max/Desktop/CarRent/Files/OilCar.bin", ios::binary);
    file.seekg(0, ios::beg);
    if (!file.is_open())
        cout << "Error";
    file.read((char*)&car, sizeof(OilCar));
    file.close();
}
