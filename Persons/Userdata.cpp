#include "Userdata.h"
#include <iostream>
#include <fstream>

using namespace std;

Userdata :: Userdata()
{
    id = 0;
}

Userdata :: Userdata(int id)
{
    this->id = id;
}

void Userdata :: SetInfo(int mode)
{
    cout << "Введите логин (пробелы недопустимы): ";
    fflush(stdin);
    fgetws(login, 30, stdin);
    login[wcscspn(login, L"\n")] = L'\0';
    while (this->CheckLogin(login) == false)
    {
        cout << "Данный логин недоступен! " << endl;
        cout << "Введите другой логин: " << endl;
        fflush(stdin);
        fgetws(login, 60, stdin);
        login[wcscspn(login, L"\n")] = L'\0';
    }
    cout << "Введите пароль (пробелы недопустимы): ";
    fflush(stdin);
    fgetws(password, 60, stdin);
    password[wcscspn(password, L"\n")] = L'\0';
    ofstream file;
    switch (mode)
    {
        case 1:
            file.open("../Files/AdminAuthentication.bin", ios::binary | ios::app);
            if (!file.is_open())
                cout << "Error";
            file.write((char*)this, sizeof(Userdata));
            file.close();
            break;
        case 2:
            file.open("../Files/UserAuthentication.bin", ios::binary | ios::app);
            if (!file.is_open())
                cout << "Error";
            file.write((char*)this, sizeof(Userdata));
            file.close();
            break;
    }
}
void Userdata :: SetData(wchar_t login[], wchar_t password[])
{
    wcscpy(this->login, login);
    wcscpy(this->password, password);
}

bool Userdata :: CheckAccess(int mode)
{
    Userdata tmp;
    ifstream file;
    if (mode == 1)
    {
        file.open("../Files/AdminAuthentication.bin", ios::binary);
        if (!file.is_open())
            cout << "Error";
            // добавить исключение
        while (file.read((char*)&tmp, sizeof(tmp)))
        {
            if (!wcscpy(tmp.login, login) && !wcscpy(tmp.password, password))
            {
                this->id = tmp.id;
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
    if (mode == 2)
    {
        file.open("../Files/UserAuthentication.bin", ios::binary);
        if (!file.is_open())
            cout << "Error";
            // добавить искючения
        while (file.read((char *) &tmp, sizeof(tmp)))
        {
            if (!wcscpy(tmp.login, login) && !wcscpy(tmp.password, password))
            {
                this->id = tmp.id;
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
}

bool Userdata :: CheckLogin(wchar_t login[])
{
    Userdata tmp;
    ifstream file;
    file.open("../Files/AdminAuthentication.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
        // добавить исключения
    while (file.read((char*)&tmp, sizeof(tmp)))
    {
        if (!wcscpy(tmp.login, login))
        {
            file.close();
            return false;
        }
    }
    file.close();

    file.open("../Files/UserAuthentication.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
        // добавить исключения
    while (file.read((char*)&tmp, sizeof(tmp)))
    {
        if (!wcscpy(tmp.login, login))
        {
            file.close();
            return false;
        }
    }
    return true;
}