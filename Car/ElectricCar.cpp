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

ElectricCar :: ElectricCar(int odo) : Car(0) { batteryCapacity = 0; }

ElectricCar :: ~ElectricCar() { }

int ElectricCar :: GetBatteryCapacity() { return batteryCapacity; }