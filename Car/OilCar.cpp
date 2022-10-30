#include "OilCar.h"
#include "Car.h"
#include <iostream>
#include <fstream>

OilCar :: OilCar () : Car()
{
    cout << "Объем двигателя: " << endl;
    cin >> engine.volume;
    while (engine.volume > 8.5 || engine.volume < 0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> engine.volume;
    }
    cout << "Расход топлива на 100км: " << endl;
    cin >> engine.consumption;
    while (engine.consumption < 0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> engine.consumption;
    }

    ofstream file("/Users/max/Desktop/CarRent/Files/OilCar.bin", ofstream::binary | ofstream::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)this, sizeof(OilCar));
    file.close();
}

OilCar :: OilCar (int odo) : Car(0) { odometer = odo; }

OilCar :: ~OilCar() { cout << "Del" << endl; }

























//void OilCar :: WriteInFile()
//{
//    ofstream file("/Users/max/Desktop/CarRent/Files/OilCar.bin", ios::binary | ios::app);
//    if (!file.is_open())
//        cout << "Error";
//    file.write((char*)this, sizeof(OilCar));
//    file.close();
//}
//
//void OilCar :: ReadFromFile()
//{
//    ifstream file("/Users/max/Desktop/CarRent/Files/OilCar.bin", ios::binary);
//    file.seekg(0, ios::beg);
//    if (!file.is_open())
//        cout << "Error";
//    file.read((char*)this, sizeof(OilCar));
//    file.close();
//}
