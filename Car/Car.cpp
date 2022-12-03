#include "Car.h"
#include <string>
#include <iostream>
#include <fstream>
#include "CarBrands.h"
#include "../ID/IdGenerator.h"
#include <cctype>

using namespace std;

Car :: Car()
{
    id = IdGenerator::GetIdForCar(); // присваем ID
    deleteMark = false;
    cruiseControl = parkingAssist = music = bluetooth = climat = seatHeating = gps = sunroof = false;
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
    CarBrands carinfo;
    carinfo.GetCarBrands(); // выводит список марок
    cout << "Выберите марку автомобиля: " << endl; // выбор
    cin >> choice;
    while (choice > 30 || choice < 1)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> choice;
    }

    //wcscpy(brand, carinfo.GetBrand(choice).c_str()); // порешать как-то
    //wcscpy(country, carinfo.GetCountry(choice).c_str());

    cout << "Модель автомобиля: " << endl;
    fflush(stdin);
    fgetws(model, 30, stdin);
    model[wcscspn(model, L"\n")] = L'\0';

    cout << "Тип кузова: " << endl;
    fflush(stdin);
    fgetws(bodyType, 30, stdin);
    bodyType[wcscspn(bodyType, L"\n")] = L'\0';

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
        case 1: wcscpy(transmissionType, L"АКПП"); break;
        case 2: wcscpy(transmissionType, L"МКПП"); break;
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

    cout << "Цвет салона" << endl;
    fflush(stdin);
    fgetws(interior.color, 30, stdin);
    interior.color[wcscspn(interior.color, L"\n")] = L'\0';

    cout << "Цвет автомобиля" << endl;
    fflush(stdin);
    fgetws(color, 30, stdin);
    color[wcscspn(color, L"\n")] = L'\0';

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

    cout << "Выберите опции: " << endl;
    cout << "1 - Круизконтроль\n"
            "2 - Паркинг-ассист\n"
            "3 - Аудиосистема\n"
            "4 - Bluetooth\n"
            "5 - Климат-контроль\n"
            "6 - Подогрев сидений\n"
            "7 - Навигация\n"
            "8 - Панорамная крыша\n"
            "9 - Есть все\n"
            "0 - Окончить ввод" << endl;
    cin >> choice;
    while (choice != 0)
    {
        while (choice > 9 || choice < 0)
        {
            cout << "Ошибка. Введите еще раз: ";
            cin >> choice;
        }

        switch (choice)
        {
            case 1: cruiseControl = true; break;
            case 2: parkingAssist = true; break;
            case 3: music = true; break;
            case 4: bluetooth = true; break;
            case 5: climat = true; break;
            case 6: seatHeating = true; break;
            case 7: gps = true; break;
            case 8: sunroof = true; break;
            case 9: cruiseControl = true, parkingAssist = true, music = true, bluetooth = true,
                    climat = true, seatHeating = true, gps = true, sunroof = true; break;
            case 0: break;
        }
        if (choice == 9)
            break;
        cin >> choice;
    }
}