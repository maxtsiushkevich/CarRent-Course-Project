#include "HybridCar.h"
#include <fstream>
#include <iostream>
#include "../Exception/Exception.h"

void HybridCar :: SetInfo()
{
    Car::SetInfo();
    int choice;
    cout << "Тип топлива: " << endl;
    cout << "1 - Бензин\n"
            "2 - Дизель\n";
    while (1)
    {
        try
        {
            cin >> choice;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (choice > 2 || choice < 1)
                throw Exception("Введен неверный пункт");
            break;
        }
        catch (BadInputException exp)
        {
            exp.Fix();
        }
        catch (Exception exp)
        {
            exp.Fix();
        }
    }
    switch (choice)
    {
        case 1: wcscpy(fuelType, L"Бензин\0"); break;
        case 2: wcscpy(fuelType, L"Дизель\0"); break;
    }

    cout << "Объем двигателя: " << endl;
    cin >> volume;
    while (1)
    {
        try
        {
            cin >> volume;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (volume < 0 || volume > 8.5)
                throw Exception("Введено неверное значение");
            break;
        }
        catch (BadInputException exp)
        {
            exp.Fix();
        }
        catch (Exception exp)
        {
            exp.Fix();
        }
    }
    cout << "Расход топлива на 100км: " << endl;
    while (1)
    {
        try
        {
            cin >> consumption;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (consumption < 0)
                throw Exception("Введено неверное значение");
            break;
        }
        catch (BadInputException exp)
        {
            exp.Fix();
        }
        catch (Exception exp)
        {
            exp.Fix();
        }
    }
    cout << "Объем батареи: " << endl;
    cin >> batteryCapacity;
    while (1)
    {
        try
        {
            cin >> batteryCapacity;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (batteryCapacity < 0)
                throw Exception("Введено неверное значение");
            break;
        }
        catch (BadInputException exp)
        {
            exp.Fix();
        }
        catch (Exception exp)
        {
            exp.Fix();
        }
    }
}