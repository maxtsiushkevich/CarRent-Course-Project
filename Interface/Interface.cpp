#include "Interface.h"
#include <iostream>
#include <fstream>
#include "../Persons/Userdata.h"
#include "../Persons/User.h"
#include <map>
using namespace std;

Interface::Interface()
{

    this->FirstMenu();
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
    string login, password;
    int mode = 1;
    cout << "Введите логин учетной записи" << endl;
    cin >> login;
    cout << "Введите пароль от учетной записи" << endl;
    cin >> password;
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
    return;
};

void Interface :: UserAuthentication()
{
    string login, password;
    int mode = 2;
    cout << "Введите логин учетной записи" << endl;
    cin >> login;
    cout << "Введите пароль от учетной записи" << endl;
    cin >> password;
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

    this->UserMainMenu();
    return;
};

void Interface :: Registation()
{
    User user;
}

void Interface :: UserMainMenu()
{
    int choice;
    while (1)
    {
        cout << "===== Личный кабинет ===== " << endl;
        cout << "1 - Информация об аккаунте" << endl;
        cout << "2 - Доступные автомобили" << endl;
        cout << "3 - Регистрация нового аккаунта пользователя" << endl;
        cout << "4 - Выйти из аккаунта" << endl;
        cout << "5 - Завершить работу" << endl;
        cin >> choice;
        while (choice < 1 || choice > 5)
        {
            cout << "Ошибка!" << endl;
            cin >> choice;
        }
        switch (choice)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                return;
            case 5:
                exit(0);

        }
    }
}

