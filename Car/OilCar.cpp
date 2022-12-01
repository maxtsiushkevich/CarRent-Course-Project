#include "OilCar.h"
#include "Car.h"
#include <iostream>
#include <fstream>

OilCar :: OilCar () : Car()
{
        volume = 0.0;
        consumption = 0.0;
}

void OilCar :: SetInfo()
{
    Car::SetInfo();
    cout << "Объем двигателя: " << endl;
    cin >> volume;
    while (volume > 8.5 || volume < 0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> volume;
    }
    cout << "Расход топлива на 100км: " << endl;
    cin >> consumption;
    while (consumption < 0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> consumption;
    }
}
























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
