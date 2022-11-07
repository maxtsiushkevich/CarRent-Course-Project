#include "IdGenerator.h"

int IdGenerator :: GetIdForCar()
{
    int sum=0;
    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/DieselCars.bin", ios::binary);
    file.seekg (0, ios::end);
    if (!file.is_open())
        sum += 0;
    else
        sum += (file.tellg() / 264);
    file.close();

    file.open("/Users/max/Desktop/CarRent/Files/PetrolCars.bin", ios::binary);
    file.seekg (0, ios::end);
    if (!file.is_open())
        sum += 0;
    else
        sum += (file.tellg() / 264);
    file.close();

    file.open("/Users/max/Desktop/CarRent/Files/ElectricCars.bin", ios::binary);
    file.seekg (0, ios::end);
    if (!file.is_open())
        sum += 0;
    else
        sum += (file.tellg() / 256);
    file.close();

    file.open("/Users/max/Desktop/CarRent/Files/HybridCars.bin", ios::binary);
    file.seekg (0, ios::end);
    if (!file.is_open())
        sum += 0;
    else
        sum += (file.tellg() / 264);
    file.close();
    return sum+1;
}
