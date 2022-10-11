#include "Car.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Car :: Car()
{
    odometer = 0;
    string str;
    int choice;
    ifstream file("/Users/max/Desktop/CarRent/Files/CarBrands.txt");
    if (!file.is_open())
        cout << "Error";
    cout << "Выберите марку автомобиля: " << endl; // выбор
    while (!file.eof())
    {
        getline(file, str);
        cout << str << endl;
    }
    cin >> choice;
    while (choice > 30 || choice < 1)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> choice;
    }
    string tmp;
    file.seekg(0, ios::beg);
    while (!file.eof())
    {
        file >> tmp;
        try
        {
            if (stoi(tmp) == choice) // добавить try catch
            {
                file >> tmp;
                file >> tmp;
                brand = tmp;
                break;
            }
        }
        catch (std::invalid_argument) {
            continue;
        }
    }
    cout << "Модель автомобиля: " << endl; // аналогично с маркой, вместе с моделью в файле хранится кузов

    cout << "Год выпуска автомобиля: " << endl;
    cin >> manufacturedYear;
    while (manufacturedYear < 2000 || manufacturedYear > 2022)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> manufacturedYear;
    }

    cout << "Коробка передач:\n1 - Автоматическа\n2 - Механическая " << endl; // выбор из АКПП или МКПП
    cin >> choice;
    while (choice > 2 || choice < 1)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> choice;
    }
    switch (choice)
    {
        case 1: transmissionType = "АКПП"; break;
        case 2: transmissionType = "МКПП"; break;
    }
    cout << "Государственный номер автомобиля: " << endl;
    cin >> carPlate; // должно соответствовать формату 9999АА-9
    // проверка на соответствие
    cout << "Стоимость аренды на день: " << endl;
    cin >> costPerDay; // >0
    costPerWeek = costPerDay * 6;
    costPerMonth = costPerDay * 25;
}