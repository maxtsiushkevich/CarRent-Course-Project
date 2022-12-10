#include "Interface.h"
#include <iostream>
#include <fstream>
#include "../Persons/User.h"
#include "../Database//Database.h"
#include "Authentication.h"
#include "CarInUsage.h"
#include "UserInterface.h"
using namespace std;

Interface::Interface()
{
    Database::GetFromDatabase(petrolCars);
    Database::GetFromDatabase(dieselCars);
    Database::GetFromDatabase(electricCars);
    Database::GetFromDatabase(hybridCars);

    CarInUsage tmp;
    tmp.GetCarsInUsage(carIdInUsage);

    Session::GetAllSessions(allSessions);
}

void Interface :: FirstMenu()
{
    int choice;
    while (1)
    {
        cout << "Выберите режим входа: \n"
                "1 - Администратор\n"
                "2 - Пользователь\n"
                "3 - Регистрация нового аккаунта пользователя\n"
                "4 - Завершить работу" << endl;
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
                if (auth.AdminAuthentication(this->admin))
                    this->AdminMainMenu();
                break;
            case 2:
                if (auth.UserAuthentication(this->user))
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

void Interface :: AdminMainMenu()
{
    int choice;
    while (1)
    {
        cout << "===== Личный кабинет ===== \n"
                "1 - Просмотреть базу данных пользователей\n"
                "2 - Просмотреть базу данных автомобилей\n"
                "3 - Просмотреть все заказы автомобилей\n"
                "4 - Просмотреть все заказы конкретного пользователя\n"
                "5 - Просмотреть все заказы конкретного автомобиля\n"
                "6 - Блокировка пользователя\n"
                "7 - Добавление автомобиля\n"
                "8 - Удаление автомобиля" << endl;
        cin >> choice;
        while (choice < 1 || choice > 8)
        {
            cout << "Ошибка! Введите еще раз:" << endl;
            cin >> choice;
        }
        switch (choice)
        {
            case 1:

        }
    }
}

