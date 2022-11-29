#include "Userdata.h"
#include <iostream>
#include <fstream>

using namespace std;

Userdata :: Userdata() { }

Userdata :: Userdata(int id, int mode)
{
    this->id = id;
    cout << "Введите логин (пробелы недопустимы): ";
    fflush(stdin);
    fgets(login, 60, stdin);
    login[strcspn(login, "\n")] = '\0';
    while (this->CheckLogin(login) == false)
    {
        cout << "Данный логин недоступен! " << endl;
        cout << "Введите другой логин: " << endl;
        fflush(stdin);
        fgets(login, 60, stdin);
        login[strcspn(login, "\n")] = '\0';
    }
    cout << "Введите пароль (пробелы недопустимы): ";
    fflush(stdin);
    fgets(password, 60, stdin);
    password[strcspn(password, "\n")] = '\0';
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

void Userdata :: SetData(char login[], char password[])
{
    strcpy(this->login, login);
    strcpy(this->password, password);
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
            if (!strcmp(tmp.login, login) && !strcmp(tmp.password, password))
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
            if (!strcmp(tmp.login, login) && !strcmp(tmp.password, password))
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

bool Userdata :: CheckLogin(char login[])
{
    Userdata tmp;
    ifstream file;
    file.open("../Files/AdminAuthentication.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
        // добавить исключения
    while (file.read((char*)&tmp, sizeof(tmp)))
    {
        if (!strcmp(tmp.login, login))
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
        if (!strcmp(tmp.login, login))
        {
            file.close();
            return false;
        }
    }
    return true;
}