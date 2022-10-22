#include "Car.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Car :: Car()
{
    string str;
    int choice;
    cruiseControl = false;
    parkingAssist = false;
    music = false;
    bluetooth = false;
    climat = false;
    seatHeating = false;
    gps = false;
    sunroof = false;
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
                file >> tmp;
                file >> tmp;
                country = tmp;
                break;
            }
        }
        catch (std::invalid_argument) {
            continue;
        }
    }
    cout << "Модель автомобиля: " << endl;
    cin >> model;
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
    cout << "Цвет автомобиля" << endl;
    cin >> exterior.color;
    cout << "Материал салона" << endl;
    cin >> interior.material;
    cout << "Цвет салона" << endl;
    cin >> interior.color;
    cout << "Государственный номер автомобиля: " << endl;
    cin >> carPlate; // должно соответствовать формату 9999АА-9
    // проверка на соответствие

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

    cout << "Количество лошадиных сил в двигателе: " << endl;
    cin >> engine.horsepower;
    while (engine.horsepower > 1000 || engine.horsepower <= 0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> engine.horsepower;
    }
    cout << "Разгон до 100: " << endl;
    cin >> engine.to100;
    while (engine.to100 < 1.0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> engine.to100;
    }
    cout << "Максимальная скорость: " << endl;
    cin >> engine.maxSpeed;
    while (engine.maxSpeed > 500 || engine.maxSpeed < 10)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> engine.maxSpeed;
    }
    file.close();
}

Car :: Car(int odo) { odometer = odo; }
Car :: ~Car() { }
string Car :: getBrand() { return brand; }
string Car :: getPlate() { return carPlate; }
int Car :: getOdometer() { return odometer; }
string Car :: getBodyType() { return bodyType; }
string Car :: getModel() { return model; }
string Car :: getCountry() { return country; }
string Car :: getTransmission() { return transmissionType; }

void Car :: printAllInfo()
{
    cout << "Модель: " << brand << ' ' << model << ' ' << manufacturedYear <<' ' << bodyType << ' ' << country << ' ' << transmissionType << ' ' << carPlate << endl;
}