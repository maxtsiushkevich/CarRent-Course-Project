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
        fgetws(login, 30, stdin);
        login[wcscspn(login, L"\n")] = L'\0';
    }
    cout << "Введите пароль (пробелы недопустимы): ";
    fflush(stdin);
    fgetws(password, 30, stdin);
    password[wcscspn(password, L"\n")] = L'\0';
    ofstream file;
    switch (mode)
    {
        case 1:
            file.open("/Users/max/Desktop/CarRent/Files/AdminAuthentication.bin", ios::binary | ios::app);
            if (!file.is_open())
                cout << "Error";
            file.write((char*)this, sizeof(Userdata));
            file.close();
            break;
        case 2:
            file.open("/Users/max/Desktop/CarRent/Files/UserAuthentication.bin", ios::binary | ios::app);
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
        file.open("/Users/max/Desktop/CarRent/Files/AdminAuthentication.bin", ios::binary);
        if (!file.is_open())
            cout << "Error";
            // добавить исключение
        while (file.read((char*)&tmp, sizeof(tmp)))
        {
            if (!wcscmp(tmp.login, login) && !wcscmp(tmp.password, password))
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
        file.open("/Users/max/Desktop/CarRent/Files/UserAuthentication.bin", ios::binary);
        if (!file.is_open())
            cout << "Error";
            // добавить искючения
        while (file.read((char *) &tmp, sizeof(tmp)))
        {
            if (!wcscmp(tmp.login, login) && !wcscmp(tmp.password, password))
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
    file.open("/Users/max/Desktop/CarRent/Files/AdminAuthentication.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while (file.read((char*)&tmp, sizeof(tmp)))
    {
        if (!wcscmp(tmp.login, login))
        {
            file.close();
            return false;
        }
    }
    file.close();

    file.open("/Users/max/Desktop/CarRent/Files/UserAuthentication.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while (file.read((char*)&tmp, sizeof(tmp)))
    {
        if (!wcscmp(tmp.login, login))
        {
            file.close();
            return false;
        }
    }
    return true;
}

void Userdata :: ChangeLogin(int id)
{
    Userdata newUserdata;
    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/UserAuthentication.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while (file.read((char*)&newUserdata, sizeof(Userdata)))
    {
        if(newUserdata.GetID() == id)
            break;
    }
    file.close();
    wchar_t login[30];
    cout << "Введите новый логин (пробелы недопустимы): ";
    fflush(stdin);
    fgetws(login, 30, stdin);
    login[wcscspn(login, L"\n")] = L'\0';
    while (CheckLogin(login) == false)
    {
        cout << "Данный логин недоступен! " << endl;
        cout << "Введите другой логин: " << endl;
        fflush(stdin);
        fgetws(login, 30, stdin);
        login[wcscspn(login, L"\n")] = L'\0';
    }
    newUserdata.SetData(login, newUserdata.GetPassword());

    ifstream file1; // для чтения
    ofstream file2; // для записи

    file1.open("/Users/max/Desktop/CarRent/Files/UserAuthentication.bin", ios::binary);
    if (!file1.is_open())
        cout << "Error";
    file2.open("/Users/max/Desktop/CarRent/Files/tmp.bin", ios::binary | ios::app);
    Userdata tmp;
    while(file1.read((char*)&tmp, sizeof(Userdata)))
    {
        if (tmp.GetID() == newUserdata.GetID())
            file2.write((char*)&newUserdata, sizeof(newUserdata));
        else
            file2.write((char*)&tmp, sizeof(newUserdata));
    }
    file1.close();
    remove("/Users/max/Desktop/CarRent/Files/UserAuthentication.bin");
    file2.close();
    rename("/Users/max/Desktop/CarRent/Files/tmp.bin","/Users/max/Desktop/CarRent/Files/UserAuthentication.bin");
}

void Userdata :: ChangePassword(int id)
{
    Userdata newUserdata;
    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/UserAuthentication.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while (file.read((char*)&newUserdata, sizeof(Userdata)))
    {
        if(newUserdata.GetID() == id)
            break;
    }
    file.close();
    wchar_t password[30];
    cout << "Введите новый пароль (пробелы недопустимы): ";
    fflush(stdin);
    fgetws(password, 30, stdin);
    password[wcscspn(password, L"\n")] = L'\0';

    newUserdata.SetData(newUserdata.GetLogin(), password);

    ifstream file1; // для чтения
    ofstream file2; // для записи

    file1.open("/Users/max/Desktop/CarRent/Files/UserAuthentication.bin", ios::binary);
    if (!file1.is_open())
        cout << "Error";
    file2.open("/Users/max/Desktop/CarRent/Files/tmp.bin", ios::binary | ios::app);
    Userdata tmp;
    while(file1.read((char*)&tmp, sizeof(Userdata)))
    {
        if (tmp.GetID() == newUserdata.GetID())
            file2.write((char*)&newUserdata, sizeof(newUserdata));
        else
            file2.write((char*)&tmp, sizeof(newUserdata));
    }
    file1.close();
    remove("/Users/max/Desktop/CarRent/Files/UserAuthentication.bin");
    file2.close();
    rename("/Users/max/Desktop/CarRent/Files/tmp.bin","/Users/max/Desktop/CarRent/Files/UserAuthentication.bin");
}