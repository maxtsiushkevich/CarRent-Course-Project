#include "ElectricCar.h"
#include <iostream>
#include <fstream>

ElectricCar :: ElectricCar()
{
    cout << "Объем батареи: " << endl;
    cin >> batteryCapacity;
    while (batteryCapacity < 0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> batteryCapacity;
    }
}

ElectricCar :: ~ElectricCar() { }


void ElectricCar :: writeInFile()
{
    ofstream file("/Users/max/Desktop/CarRent/Files/ElectricCar.bin", ios::binary |  ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)this, sizeof(ElectricCar));
    file.close();
}

void ElectricCar :: readFromFile()
{
    ifstream file("/Users/max/Desktop/CarRent/Files/ElectricCar.bin", ios::binary);
    file.seekg(0, ios::beg);
    if (!file.is_open())
        cout << "Error";
    file.read((char*)this, sizeof(ElectricCar));
    file.close();
}