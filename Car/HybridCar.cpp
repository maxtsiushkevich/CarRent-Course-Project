#include "HybridCar.h"
#include <fstream>
#include <iostream>


void HybridCar :: SetInfo()
{
    Car::SetInfo();
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
        case 1: strcpy(fuelType, "Бензин"); break;
        case 2: strcpy(fuelType, "Дизель"); break;
    }

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

    cout << "Объем батареи: " << endl;
    cin >> batteryCapacity;
    while (batteryCapacity < 0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> batteryCapacity;
    }
}