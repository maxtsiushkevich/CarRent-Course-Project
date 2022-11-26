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
    int choice;
    odometer = 0;
    cruiseControl = parkingAssist = music = bluetooth = climat = seatHeating = gps = sunroof = false;
    CarBrands carinfo;
    carinfo.GetCarBrands(); // выводит список марок
    cout << "Выберите марку автомобиля: " << endl; // выбор
    cin >> choice;
    while (choice > 30 || choice < 1)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> choice;
    }
    brand.reserve(60);
    brand = carinfo.GetBrand(choice); // в зависимости от выбора возвращается марка и страна этой марки

    country.reserve(60);
    country = carinfo.GetCountry(choice);

    cout << "Модель автомобиля: " << endl;
    fflush(stdin);
    model.reserve(60);
    getline(cin, model);
    while (model.size() > 60 || model.size() == 0)
    {
        cout << "Слишком длинная запись или пустой ввод. Введите еще раз: ";
        model.reserve(60);
        getline(cin, model);
    }

    cout << model.size() << endl;

    cout << "Тип кузова: " << endl;
    fflush(stdin);
    bodyType.reserve(60);
    getline(cin, bodyType);
    while (bodyType.size() > 60 || bodyType.size() == 0)
    {
        cout << "Слишком длинная запись или пустой ввод. Введите еще раз: ";
        bodyType.reserve(60);
        getline(cin, bodyType);
    }

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
        case 1: transmissionType = "АКПП"; break;
        case 2: transmissionType = "МКПП"; break;
    }

    cout << "Количество мест: " << endl;
    cin >> numberOfSeats;
    while (numberOfSeats < 2 || numberOfSeats > 7)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> numberOfSeats;
    }

    cout << "Материал салона" << endl;
    interior.material.reserve(60);
    fflush(stdin);
    getline(cin, interior.material);
    while (interior.material.size() > 60 || interior.material.size() == 0)
    {
        cout << "Слишком длинная запись или пустой ввод. Введите еще раз: ";
        interior.material.reserve(60);
        getline(cin, interior.material);
    }

    cout << "Цвет салона" << endl;
    interior.color.reserve(60);
    fflush(stdin);
    getline(cin, interior.color);
    while (interior.color.size() > 60 || interior.color.size() == 0)
    {
        cout << "Слишком длинная запись или пустой ввод. Введите еще раз: ";
        interior.color.reserve(60);
        getline(cin, interior.color);
    }

    cout << "Цвет автомобиля" << endl;
    color.reserve(60);
    fflush(stdin);
    getline(cin, color);
    while (color.size() > 60 || color.size() == 0)
    {
        cout << "Слишком длинная запись или пустой ввод. Введите еще раз: ";
        color.reserve(60);
        getline(cin, color);
    }


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
    costPerWeek = costPerDay * 6;
    costPerMonth = costPerDay * 25;

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

        //toupper(model[0]);
        //toupper(bodyType[0]);
    }
}