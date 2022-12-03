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
    Database::GetFromDatabase(hybridCar);
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
        switch (choice)
        {
            case 1:
                Authentication auth;
                auth.AdminAuthentication();
                break;
            case 2:
                Authentication auth;
                auth.UserAuthentication();
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
    User user;
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
        cout << "5 - Настройка аккаунта"
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
                UserAccountInfo();
                break;
            case 2:

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
    cout << "Баланс: "
    cout << GetCo
    //cout << '|' << setw(5) << left << user.GetName() << setw(5) << '|' << setw(5) << user.GetSurname() << endl;
    //cout << '|' << setw(5) << left << user.GetName() << setw(5) << '|' << setw(5) << user.GetSurname() << endl;
    for (auto it = hybridCar.begin(); it != hybridCar.end(); ++it)
    {
        cout << "—————————————————————————————————" << endl;
        wcout << '|' << setw(15) << left << it->GetBrand() << '|' << setw(15) << left << it->GetModel() << '|' << endl;
    }
    cout << "——————————————————————————" << endl;
    //cout << '|' << setw(5) << left << user.GetName() << setw(5) << '|' << setw(5) << user.GetSurname() << endl;
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

