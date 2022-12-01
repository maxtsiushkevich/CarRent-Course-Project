#include "ElectricCar.h"
#include <iostream>
#include <fstream>

ElectricCar :: ElectricCar()
{
    batteryCapacity = 0;
}

void ElectricCar :: SetInfo()
{
    Car::SetInfo();
    cout << "Объем батареи: " << endl;
    cin >> batteryCapacity;
    while (batteryCapacity < 0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> batteryCapacity;
    }
}