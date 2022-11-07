#include "HybridCar.h"
#include <fstream>
#include <iostream>

HybridCar :: HybridCar() : Car(), OilCar(), ElectricCar()
{
    int choice;
    cout << "Тип топлива: " << endl;
    cout << "1 - Бензин\n"
            "2 - Дизель\n";
    cin >> choice;
    while (choice > 2 || choice < 1)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> choice;
    }
    switch (choice)
    {
        case 1: fuelType = "Бензин"; break;
        case 2: fuelType = "Дизель"; break;

    }
}

HybridCar :: HybridCar(int odo) : Car(0), OilCar(0), ElectricCar(0) { odometer = odo; }
HybridCar :: ~HybridCar() { }