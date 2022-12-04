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


//bool Interface :: AdminAuthentication()
//{
//    wchar_t login[30], password[30];
//    int mode = 1;
//    cout << "Введите логин учетной записи" << endl;
//    fflush(stdin);
//    fgetws(login, 30, stdin);
//    login[wcscspn(login, L"\n")] = L'\0';
//    cout << "Введите пароль от учетной записи" << endl;
//    fflush(stdin);
//    fgetws(password, 30, stdin);
//    password[wcscspn(password, L"\n")] = L'\0';
//    account.SetData(login, password);
//    while(!account.CheckAccess(mode))
//    {
//        char tmp;
//        fflush(stdin);
//        cout << "Ошибка! Введите логин и пароль заново" << endl;
//        cout << "Если хотите выбрать другой режим входа, введите 1\nЕсли хотите продолжить, нажмите любую другую кнопку" << endl;
//        tmp = cin.get();
//        if (tmp == '1')
//            return false;
//        cout << "Логин" << endl;
//        fflush(stdin);
//        fgetws(login, 30, stdin);
//        login[wcscspn(login, L"\n")] = L'\0';
//        cout << "Пароль" << endl;
//        fflush(stdin);
//        fgetws(password, 30, stdin);
//        password[wcscspn(password, L"\n")] = L'\0';
//        account.SetData(login, password);
//    }
//    cout << "Вход выполнен!" << endl;
//    ifstream file;
//    file.open("/Users/max/Desktop/CarRent/Files/Admin.bin", ios::binary);
//    if (!file.is_open())
//        cout << "Error";
//    while(file.read((char*)&admin, sizeof(Admin)))
//    {
//        if (admin.GetID() == account.GetID())
//            break;
//    }
//    file.close();
//    return true;
//};
//bool Interface :: UserAuthentication()
//{
//    wchar_t login[30], password[30];
//    int mode = 2;
//    cout << "Введите логин учетной записи" << endl;
//    fflush(stdin);
//    fgetws(login, 30, stdin);
//    login[wcscspn(login, L"\n")] = L'\0';
//    cout << "Введите пароль от учетной записи" << endl;
//    fflush(stdin);
//    fgetws(password, 30, stdin);
//    password[wcscspn(password, L"\n")] = L'\0';
//    account.SetData(login, password);
//    while(!account.CheckAccess(mode))
//    {
//        char tmp;
//        fflush(stdin);
//        cout << "Ошибка! Введите логин и пароль заново" << endl;
//        cout << "Если хотите выбрать другой режим входа, введите 1\nЕсли хотите продолжить, нажмите любую другую кнопку" << endl;
//        tmp = cin.get();
//        if (tmp == '1')
//            return false;
//        cout << "Логин" << endl;
//        fflush(stdin);
//        fgetws(login, 30, stdin);
//        login[wcscspn(login, L"\n")] = L'\0';
//        cout << "Пароль" << endl;
//        fflush(stdin);
//        fgetws(password, 30, stdin);
//        password[wcscspn(password, L"\n")] = L'\0';
//        account.SetData(login, password);
//    }
//    cout << "Вход выполнен!" << endl;
//
//    ifstream file;
//    file.open("/Users/max/Desktop/CarRent/Files/User.bin", ios::binary);
//    if (!file.is_open())
//        cout << "Error";
//    while(file.read((char*)&user, sizeof(User)))
//    {
//        if (user.GetID() == account.GetID())
//            break;
//    }
//    file.close();
//    return true;
//};

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
    // задержка
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

