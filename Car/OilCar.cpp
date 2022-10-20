#include "OilCar.h"
#include "Car.h"
#include <iostream>
#include <fstream>

OilCar :: OilCar () : Car()
{
    cout << "Объем двигателя: " << endl;
    cin >> engine.engineVolume;
    while (engine.consumption > 8.5 || engine.consumption < 0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> engine.engineVolume;
    }
    cout << "Расход топлива на 100км: " << endl;
    cin >> engine.consumption;
    while (engine.consumption < 0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> engine.consumption;
    }
};

OilCar :: OilCar (int odo) : Car(0)
{ odometer = odo; }

OilCar :: ~OilCar() { }

void OilCar :: writeInFile()
{
    ofstream file("/Users/max/Desktop/CarRent/OilCar.bin", ios::binary |  ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)this, sizeof(OilCar));
    file.close();
}

void OilCar :: readFromFile()
{
    ifstream file("/Users/max/Desktop/CarRent/OilCar.bin", ios::binary);
    file.seekg(0, ios::beg);
    if (!file.is_open())
        cout << "Error";
    file.read((char*)this, sizeof(OilCar));
    file.close();
}

void OilCar :: printAll()
{
    cout << "Модель: " << brand << ' ' << model << ' ' << manufacturedYear <<' ' << bodyType << ' ' << country << ' ' << transmissionType << ' ' << carPlate << endl;
}