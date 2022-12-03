#include "Interface.h"
#include <iostream>
#include <fstream>
#include "../Persons/Userdata.h"
#include "../Persons/User.h"
#include "../Database//Database.h"
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
                this->AdminAuthentication();
                break;
            case 2:
                this->UserAuthentication();
                break;
            case 3:
                this->Registation();
                break;
            case 4:
                exit(0);
        }
    }
}

void Interface :: AdminAuthentication()
{
    char login[60], password[60];
    int mode = 1;
    cout << "Введите логин учетной записи" << endl;
    fflush(stdin);
    fgets(login, 60, stdin);
    login[strcspn(login, "\n")] = '\0';
    cout << "Введите пароль от учетной записи" << endl;
    fflush(stdin);
    fgets(password, 60, stdin);
    password[strcspn(password, "\n")] = '\0';
    account.SetData(login, password);
    while(!account.CheckAccess(mode))
    {
        char tmp;
        fflush(stdin);
        cout << "Ошибка! Введите логин и пароль заново" << endl;
        cout << "Если хотите выбрать другой режим входа, введите 1\nЕсли хотите продолжить, нажмите любую другую кнопку" << endl;
        tmp = cin.get();
        if (tmp == '1')
            return;
        cout << "Логин" << endl;
        fflush(stdin);
        fgets(login, 60, stdin);
        login[strcspn(login, "\n")] = '\0';
        cout << "Пароль" << endl;
        fflush(stdin);
        fgets(password, 60, stdin);
        password[strcspn(password, "\n")] = '\0';
        account.SetData(login, password);
    }
    cout << "Вход выполнен!" << endl;
    ifstream file;
    file.open("../Files/Admin.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while(file.read((char*)&admin, sizeof(Admin)))
    {
        if (admin.GetID() == account.GetID())
            break;
    }
    file.close();

   //this->AdminMainMenu();

    return;
};

void Interface :: UserAuthentication()
{
    char login[60], password[60];
    int mode = 2;
    cout << "Введите логин учетной записи" << endl;
    fflush(stdin);
    fgets(login, 60, stdin);
    login[strcspn(login, "\n")] = '\0';
    cout << "Введите пароль от учетной записи" << endl;
    fflush(stdin);
    fgets(password, 60, stdin);
    password[strcspn(password, "\n")] = '\0';
    account.SetData(login, password);
    while(!account.CheckAccess(mode))
    {
        char tmp;
        fflush(stdin);
        cout << "Ошибка! Введите логин и пароль заново" << endl;
        cout << "Если хотите выбрать другой режим входа, введите 1\nЕсли хотите продолжить, нажмите любую другую кнопку" << endl;
        tmp = cin.get();
        if (tmp == '1')
            return;
        cout << "Логин" << endl;
        cin >> login;
        cout << "Пароль" << endl;
        cin >> password;
        account.SetData(login, password);
    }
    cout << "Вход выполнен!" << endl;

    // нужно инициализировать user
    ifstream file;
    file.open("../Files/User.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while(file.read((char*)&user, sizeof(User)))
    {
        if (user.GetID() == account.GetID())
            break;
    }
    file.close();

    this->UserMainMenu();
    return;
};

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
    //cout << "Имя: ";
    //cout << '|' << setw(5) << left << user.GetName() << setw(5) << '|' << setw(5) << user.GetSurname() << endl;
    //cout << '|' << setw(5) << left << user.GetName() << setw(5) << '|' << setw(5) << user.GetSurname() << endl;
    for (auto it = hybridCar.begin(); it != hybridCar.end(); ++it)
    {
        cout << "—————————————————————————————————" << endl;
        cout << '|';
        cout.width(15);
        cout << left << it->GetBrand();
        cout << '|';
        cout.width(15);
        cout << left << it->GetModel();
        cout << '|' << endl;
        //cout << '|' << setw(15) << left << it->GetBrand() << '|' << setw(15) << left << it->GetModel() << '|' << endl;
    }
    cout << "——————————————————————————" << endl;
    //cout << '|' << setw(5) << left << user.GetName() << setw(5) << '|' << setw(5) << user.GetSurname() << endl;
    //cout << user.GetName() << ' ' << user.GetSurname() << endl;
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

