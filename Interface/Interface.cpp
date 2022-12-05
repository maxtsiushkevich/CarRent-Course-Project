#include "Interface.h"
#include <iostream>
#include <fstream>
#include "../Persons/Userdata.h"
#include "../Persons/User.h"
#include "../Database//Database.h"
#include "Authentication.h"
using namespace std;

Interface::Interface()
{
    Database::GetFromDatabase(petrolCars);
    Database::GetFromDatabase(dieselCars);
    Database::GetFromDatabase(electricCars);
    Database::GetFromDatabase(hybridCars);
}
void Interface :: FirstMenu()
{
    int choice;
    while (1)
    {
        cout << "Выберите режим входа: " << endl;
        cout << "1 - Администратор" << endl;
        cout << "2 - Пользователь" << endl;
        cout << "3 - Регистрация нового аккаунта пользователя" << endl;
        cout << "4 - Завершить работу" << endl;
        cin >> choice;
        while (choice < 1 || choice > 4)
        {
            cout << "Ошибка!" << endl;
            cin >> choice;
        }
        Authentication auth;
        switch (choice)
        {
            case 1:
                if (auth.AdminAuthentication())
                    this->AdminMainMenu();
                break;
            case 2:
                if (auth.UserAuthentication())
                    this->UserMainMenu();
                break;
            case 3:
                this->Registation();
                break;
            case 4:
                exit(0);
        }
    }
}

void Interface :: Registation()
{
    user.SetInfo();
}

void Interface :: UserMainMenu()
{
    int choice;
    while (1)
    {
        cout << "===== Личный кабинет ===== " << endl;
        cout << "1 - Информация об аккаунте" << endl;
        cout << "2 - Автомобили для заказа" << endl;
        cout << "3 - История поездок" << endl;
        cout << "4 - Пополнение счета" << endl;
        cout << "5 - Настройка аккаунта" << endl;
        cout << "5 - Выйти из аккаунта" << endl;
        cout << "6 - Завершить работу" << endl;
        cin >> choice;
        while (choice < 1 || choice > 7)
        {
            cout << "Ошибка!" << endl;
            cin >> choice;
        }
        switch (choice)
        {
            case 1:
                this->UserAccountInfo();
                break;
            case 2:
                this->ChoosingCar();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                return;
            case 6:
                exit(0);
        }
    }
}

void Interface :: UserAccountInfo()
{
    cout << "Имя: ";
    wcout << user.GetName() << ' ' << user.GetSurname() << endl;
    cout << "Возраст: ";
    cout << user.GetAge()<< endl;
    cout << "Баланс: ";
    cout << user.GetCount() << endl;
    cout << "Текущий статус: ";
    wcout << user.GetStatus()<< endl;
    cout << "Номер паспорта, привязанного к аккаунту: ";
    wcout << user.GetPassportNum() << endl;
    cout << "Номер телефона: ";
    wcout << user.GetPhoneNumber() << endl;
    cout << "Адрес: ";
    wcout << user.GetCountry() << ", " << user.GetCity() << ", " << user.GetStreet() << ' ' << user.GetHouse() << '-' << user.GetFlat() << endl;
}

void Interface :: AdminMainMenu()
{
    int choice;
    while (1)
    {
        cout << "===== Личный кабинет ===== " << endl;
        cout << "1 - Просмотреть базу данных пользователей" << endl;
        cout << "2 - Просмотреть базу данных автомобилей" << endl;
        cout << "3 - Просмотреть все заказы автомобилей" << endl;
        cout << "4 - Просмотреть все заказы конкретного пользователя" << endl;
        cout << "5 - Просмотреть все заказы конкретного автомобиля" << endl;
        cout << "6 - Блокировка пользователя" << endl;
        cout << "7 - Добавление автомобиля" << endl;
        cout << "8 - Удаление автомобиля" << endl;
    }
}

void Interface :: ChoosingCar()
{
    int choice;
    cout << "Какой тип автомобилей вас интересует?\n"
            "1 - Бензиновые автомобили\n"
            "2 - Дизельные автомобили\n"
            "3 - Электрические автомобили\n"
            "4 - Гибридные автомобили" << endl;
    cin >> choice;
    while (choice < 0 | choice > 4)
    {
        cout << "Ошибка. Введите еще раз:" << endl;
        cin >> choice;
    }
    this->ShowCars(choice);

    cout << "1 - Выход в меню пользователя\n"
            "2 - Выбор автомобиля\n"
            "3 - Просмотр подробной информации об автомобиле" << endl;
    int tmp;
    cin >> tmp;
    while (tmp < 0 | tmp >3)
    {
        cout << "Ошибка. Введите еще раз:" << endl;
        cin >> tmp;
    }
    switch (tmp)
    {
        case 1:
            return;
        case 2:
            cout << "Введите номер желаемого автомобиля: " << endl;
            int carId;
            cin >> carId;
            while(!session.CreateSession(user.GetID(), carId, FindCost(choice, carId), user.GetCount()))
            {
                cout << "Желаете продолжить?\n"
                        "Для ввода другого номера введите '1'\n"
                        "Для выхода в меню введите '2'" << endl;
                int tmp;
                cin >> tmp;
                while (tmp < 1 || tmp > 2)
                {
                    cout << "Ошибка ввода" << endl;
                }
                if (tmp == 1)
                {
                    cout << "Введите номер желаемого автомобиля: " << endl;
                    cin >> carId;
                }
                if (tmp == 2)
                    break;

            }
            break;
        case 3:
            this->ShowDetailedInfo(); // логика как и в case 2
    }
}

void Interface :: ShowCars(int choice)
{
    switch (choice)
    {
        case 1:
            if (petrolCars.empty())
            {
                cout << "Нет доступных автомобилей" << endl;
                break;
            }
            for (auto it = petrolCars.begin(); it != petrolCars.end(); ++it)
            {
                wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15) << it->GetModel();
                cout << '|' << setw(15) << left << it->GetManufacturedYear() << endl;
            }
            break;
        case 2:
            if (dieselCars.empty())
            {
                cout << "Нет доступных автомобилей" << endl;
                break;
            }
            for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
            {
                wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15) << it->GetModel();
                cout << '|' << setw(15) << left << it->GetManufacturedYear() << endl;
            }
            break;
        case 3:
            if (electricCars.empty())
            {
                cout << "Нет доступных автомобилей" << endl;
                break;
            }
            for (auto it = electricCars.begin(); it != electricCars.end(); ++it)
            {
                wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15) << it->GetModel();
                cout << '|' << setw(15) << left << it->GetManufacturedYear() << endl;
            }
            break;
        case 4:
            if (hybridCars.empty())
            {
                cout << "Нет доступных автомобилей" << endl;
                break;
            }
            for (auto it = hybridCars.begin(); it != hybridCars.end(); ++it)
            {
                wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15) << it->GetModel();
                cout << '|' << setw(15) << left << it->GetManufacturedYear() << endl;
            }
            break;
    }
}

int Interface :: FindCost(int choice, int carId)
{
    if (choice == 1)
    {
        for (auto it = petrolCars.begin(); it != petrolCars.end(); ++it)
        {
            if (it->GetID() == carId)
                return it->GetCostPerDay();
        }
    }
    if (choice == 2)
    {
        for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
        {
            if (it->GetID() == carId)
                return it->GetCostPerDay();
        }
    }
    if (choice == 3)
    {
        for (auto it = electricCars.begin(); it != electricCars.end(); ++it)
        {
            if (it->GetID() == carId)
                return it->GetCostPerDay();
        }
    }
    if (choice == 4)
    {
        for (auto it = hybridCars.begin(); it != hybridCars.end(); ++it)
        {
            if (it->GetID() == carId)
                return it->GetCostPerDay();
        }
    }
    return 0;
}