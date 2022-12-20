#include "Authentication.h"
#include <iostream>
#include <fstream>

using namespace std;

bool Authentication::AdminAuthentication(Admin &admin) {
    wchar_t login[30], password[30];
    int mode = 1;
    cout << "Введите логин учетной записи" << endl;
    fflush(stdin);
    fgetws(login, 30, stdin);
    login[wcscspn(login, L"\n")] = L'\0';
    cout << "Введите пароль от учетной записи" << endl;
    fflush(stdin);
    fgetws(password, 30, stdin);
    password[wcscspn(password, L"\n")] = L'\0';
    account.SetData(login, password);
    while (account.CheckAccess(mode) == false) {
        char tmp;
        fflush(stdin);
        cout << "Ошибка! Введите логин и пароль заново" << endl;
        cout << "Если хотите выбрать другой режим входа, введите 1\nЕсли хотите продолжить, нажмите любую другую кнопку"
             << endl;
        tmp = cin.get();
        if (tmp == '1')
            return false;
        cout << "Логин" << endl;
        fflush(stdin);
        fgetws(login, 30, stdin);
        login[wcscspn(login, L"\n")] = L'\0';
        cout << "Пароль" << endl;
        fflush(stdin);
        fgetws(password, 30, stdin);
        password[wcscspn(password, L"\n")] = L'\0';
        account.SetData(login, password);
    }
    cout << "Вход выполнен!" << endl;
    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/Admin.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while (file.read((char *) &admin, sizeof(Admin))) {
        if (admin.GetID() == account.GetID())
            break;
    }
    file.close();
    return true;
}

bool Authentication::UserAuthentication(User &user) {
    wchar_t login[30], password[30];
    int mode = 2;
    cout << "Введите логин учетной записи" << endl;
    fflush(stdin);
    fgetws(login, 30, stdin);
    login[wcscspn(login, L"\n")] = L'\0';
    cout << "Введите пароль от учетной записи" << endl;
    fflush(stdin);
    fgetws(password, 30, stdin);
    password[wcscspn(password, L"\n")] = L'\0';
    account.SetData(login, password);
    while (!account.CheckAccess(mode)) {
        char tmp;
        fflush(stdin);
        cout << "Ошибка! Введите логин и пароль заново" << endl;
        cout << "Если хотите выбрать другой режим входа, введите 1\nЕсли хотите продолжить, нажмите любую другую кнопку"
             << endl;
        tmp = cin.get();
        if (tmp == '1')
            return false;
        cout << "Логин" << endl;
        fflush(stdin);
        fgetws(login, 30, stdin);
        login[wcscspn(login, L"\n")] = L'\0';
        cout << "Пароль" << endl;
        fflush(stdin);
        fgetws(password, 30, stdin);
        password[wcscspn(password, L"\n")] = L'\0';
        account.SetData(login, password);
    }
    cout << "Вход выполнен!" << endl;
    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/User.bin", ios::binary);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла";
        return false;
    }
    while (file.read((char *) &user, sizeof(User))) {
        if (user.GetID() == account.GetID()) {
            file.close();
            break;
        }
    }
    return true;
};