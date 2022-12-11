#include "Car.h"
#include <iostream>
#include <fstream>
#include "CarBrands.h"
#include "../ID/IdGenerator.h"

using namespace std;

Car :: Car()
{
    id = 0; // присваем ID
    deleteMark = false;
    manufacturedYear = 0;
    numberOfSeats = 0;
    horsepower = 0;
    to100 = 0.0;
    maxSpeed = 0;
    costPerDay = 0;
}

void Car :: SetInfo()
{
    int choice;
    id = IdGenerator::GetIdForCar(); // присваем ID
    CarBrands carinfo;


    carinfo.GetCarBrands(); // выводит список марок
    cout << "Выберите марку автомобиля: " << endl; // выбор
    cin >> choice;
    while (choice > 30 || choice < 1)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> choice;
    }

    wcscpy(brand, carinfo.GetBrand(choice).c_str());
    wcscpy(country, carinfo.GetCountry(choice).c_str());

    cout << "Модель автомобиля: " << endl;
    fflush(stdin);
    fgetws(model, 30, stdin);
    model[wcscspn(model, L"\n")] = L'\0';
    model[0] = towupper(model[0]);

    cout << "Тип кузова: " << endl;
    fflush(stdin);
    fgetws(bodyType, 30, stdin);
    bodyType[wcscspn(bodyType, L"\n")] = L'\0';
    bodyType[0] = towupper(bodyType[0]);

    cout << "Год выпуска автомобиля: " << endl;
    cin >> manufacturedYear;
    while (manufacturedYear < 1930 || manufacturedYear > 2022)
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
        case 1: wcscpy(transmissionType, L"АКПП\0"); break;
        case 2: wcscpy(transmissionType, L"МКПП\0"); break;
    }

    cout << "Количество мест: " << endl;
    cin >> numberOfSeats;
    while (numberOfSeats < 2 || numberOfSeats > 7)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> numberOfSeats;
    }

    cout << "Материал салона" << endl;
    fflush(stdin);
    fgetws(interior.material, 30, stdin);
    interior.material[wcscspn(interior.material, L"\n")] = L'\0';
    interior.material[0] = towupper(interior.material[0]);

    cout << "Цвет салона" << endl;
    fflush(stdin);
    fgetws(interior.color, 30, stdin);
    interior.color[wcscspn(interior.color, L"\n")] = L'\0';
    interior.color[0] = towupper(interior.color[0]);

    cout << "Цвет автомобиля" << endl;
    fflush(stdin);
    fgetws(color, 30, stdin);
    color[wcscspn(color, L"\n")] = L'\0';
    color[0] = towupper(color[0]);

    cout << "Количество лошадиных сил в двигателе: " << endl;
    cin >> horsepower;
    while (horsepower > 1000 || horsepower <= 0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> horsepower;
    }

    cout << "Разгон до 100: " << endl;
    cin >> to100;
    while (to100 < 1.0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> to100;
    }

    cout << "Максимальная скорость: " << endl;
    cin >> maxSpeed;
    while (maxSpeed > 500 || maxSpeed < 10)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> maxSpeed;
    }

    cout << "Стоимость аренды на день: " << endl;
    cin >> costPerDay;
    while (costPerDay < 0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> costPerDay;
    }
}