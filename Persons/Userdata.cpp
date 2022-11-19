#include "Userdata.h"
#include <iostream>
#include <fstream>

using namespace std;

Userdata :: Userdata() { }

Userdata :: Userdata(int id, int mode)
{
    this->id = id;
    cout << "Введите логин: ";
    cin >> login;
    while (this->CheckLogin(login) == false)
    {
        cout << "Данный логин недоступен! " << endl;
        cout << "Введите другой логин: " << endl;
        cin >> login;
    }
    cout << "Введите пароль: ";
    cin >> password;
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

void Userdata :: SetData(string login, string password)
{
    this->login = login;
    this->password = password;
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
            if (tmp.login == login && tmp.password == password)
            {
                file.close();
                return true;
            }
            else
            {
                file.close();
                return false;
            }
        }
    }
    if (mode == 2)
    {
        file.open("../Files/UserAuthentication.bin", ios::binary);
        if (!file.is_open())
            cout << "Error";
            // добавить искючения
        while (file.read((char *) &tmp, sizeof(tmp)))
        {
            if (tmp.login == login && tmp.password == password)
            {
                file.close();
                return true;
            }
            else
            {
                file.close();
                return false;
            }
        }
    }
}

bool Userdata :: CheckLogin(string login)
{
    Userdata tmp;
    ifstream file;
    file.open("../Files/AdminAuthentication.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
        // добавить исключения
    while (file.read((char*)&tmp, sizeof(tmp)))
    {
        if (tmp.login == login)
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
        if (tmp.login == login)
        {
            file.close();
            return false;
        }
    }
    return true;
}