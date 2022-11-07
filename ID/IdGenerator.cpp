#include "IdGenerator.h"

int IdGenerator :: GetIdForCar()
{
    int sum=0;
    ifstream file;
    file.open("../Files/DieselCars.bin", ios::binary);
    file.seekg (0, ios::end);
    if (!file.is_open())
        sum += 0;
    else
        sum += (file.tellg() / 264);
    file.close();

    file.open("../Files/PetrolCars.bin", ios::binary);
    file.seekg (0, ios::end);
    if (!file.is_open())
        sum += 0;
    else
        sum += (file.tellg() / 264);
    file.close();

    file.open("../Files/ElectricCars.bin", ios::binary);
    file.seekg (0, ios::end);
    if (!file.is_open())
        sum += 0;
    else
        sum += (file.tellg() / 256);
    file.close();

    file.open("../Files/HybridCars.bin", ios::binary);
    file.seekg (0, ios::end);
    if (!file.is_open())
        sum += 0;
    else
        sum += (file.tellg() / 264);
    file.close();

    return sum+1;
}
int IdGenerator :: GetIdForPerson()
{
    int sum = 0;
    ifstream file;
    file.open("../Files/Users.bin", ios::binary);
    file.seekg(0, ios::end);
    if (!file.is_open())
        sum += 0;
    else
        sum += file.tellg();
    file.close();

    file.open("../Files/Admins.bin", ios::binary);
    file.seekg (0, ios::end);
    if (!file.is_open())
        sum += 0;
    else
        sum += file.tellg();
    file.close();

    return sum+1;
}