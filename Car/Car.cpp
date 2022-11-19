#include "Car.h"
#include <string>
#include <iostream>
#include <fstream>
#include "CarBrands.h"
#include "../ID/IdGenerator.h"

using namespace std;

Car :: Car()
{
    id = IdGenerator::GetIdForCar();
    deleteMark = false;
    int choice;
    odometer = 0;
    cruiseControl = parkingAssist = music = bluetooth = climat = seatHeating = gps = sunroof = false;
    CarBrands carinfo;
    carinfo.GetCarBrands();
    cout << "Выберите марку автомобиля: " << endl; // выбор
    cin >> choice;
    while (choice > 30 || choice < 1)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> choice;
    }
    brand = carinfo.GetBrand(choice);
    country = carinfo.GetCountry(choice);

    cout << "Модель автомобиля: " << endl;
    fflush(stdin);
    getline(cin, model);

    cout << "Тип кузова: " << endl;
    cin >> bodyType;

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

    cout << "Количество мест: " << endl;
    cin >> numberOfSeats;
    while (numberOfSeats < 2 || numberOfSeats > 7)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> numberOfSeats;
    }

    cout << "Материал салона" << endl;
    cin >> interior.material;
    cout << "Цвет салона" << endl;
    cin >> interior.color;
    cout << "Цвет автомобиля" << endl;
    cin >> color;

    //cout << "Государственный номер автомобиля в формате 1111АА-1: " << endl;
    //cin >> plate;

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
        cin >> choice;
    }
}