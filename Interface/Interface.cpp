#include "Interface.h"
#include <iostream>
#include <fstream>
using namespace std;

//Interface :: Interface()
//{
//    cout << "1 - Войти как администатор\n"
//            "2 - Войти как пользователь\n"
//            "3 - Регистрация нового пользователя\n";
//    cin >> mode;
//    while (mode > 3 || mode < 1)
//    {
//        cout << "Не верный ввод. Введите еще раз: " << endl;
//        cin >> mode;
//    }
//    if (mode == 1)
//        this->authentication();
//    if (mode == 2)
//        this->authentication();
//    if (mode == 3)
//        this->registration();
//
//}
//
//Interface :: ~Interface() { }
//
//void Interface :: authentication()
//{
//    string login, password;
//    cout << "Введите логин: ";
//    cin >> login;
//    cout << "Введите пароль: ";
//    cin >> password;
//    while (userdata.login != login && userdata.password != password)
//    {
//        if (mode == 1)
//        {
//            ifstream file("/Users/max/Desktop/CarRent/Files/adminAuthentication.bin", ios::binary);
//            file.seekg(0, ios::beg);
//            if (!file.is_open())
//                cout << "Error";
//            while (1)
//            {
//                file.read((char*)&userdata, sizeof(userdata));
//                if (userdata.login == login && userdata.password == password)
//                {
//                    login = userdata.login;
//                    password = userdata.password;
//                    cout << "Вход выполнен!" << endl;
//                    file.close();
//                    return;
//                }
//                if (file.eof())
//                {
//                    file.seekg(0, ios::beg);
//                    cout << "Пользователь не найден!" << endl;
//                    cout << "Введите данные снова!" << endl;
//                    cout << "Введите логин: ";
//                    cin >> login;
//                    cout << "Введите логин: ";
//                    cin >> password;
//                }
//            }
//        }
//
//        if (mode == 2)
//        {
//            ifstream file("/Users/max/Desktop/CarRent/Files/userAuthentication.bin", ios::binary);
//            file.seekg(0, ios::beg);
//            if (!file.is_open())
//                cout << "Error";
//            while (1)
//            {
//                file.read((char*)&userdata, sizeof(userdata));
//                if (userdata.login == login && userdata.password == password)
//                {
//                    login = userdata.login;
//                    password = userdata.password;
//                    cout << "Вход выполнен!" << endl;
//                    file.close();
//                    return;
//                }
//                if (file.eof())
//                {
//                    file.seekg(0, ios::beg);
//                    cout << "Пользователь не найден!" << endl;
//                    cout << "Введите данные снова!" << endl;
//                    cout << "Введите логин: ";
//                    cin >> login;
//                    cout << "Введите логин: ";
//                    cin >> password;
//                }
//            }
//        }
//    }
//}
//
//void Interface :: registration()
//{
//    string login, password;
//    cout << "Введите логин: ";
//    cin >> login;
//    ifstream file1("/Users/max/Desktop/CarRent/Files/userAuthentication.bin", ios::binary);
//    file1.seekg(0, ios::beg);
//    while (file1.read((char*)&userdata, sizeof(userdata)))
//    {
//        if (userdata.login == login)
//        {
//            cout << "Такой логин уже существует. Введите другой: ";
//            cin >> login;
//        }
//    }
//    file1.close();
//    cout << "Введите пароль: ";
//    cin >> password;
//    userdata.login = login;
//    userdata.password = password;
//    ofstream file("/Users/max/Desktop/CarRent/Files/userAuthentication.bin", ios::binary | ios::app);
//    if (!file.is_open())
//        cout << "Error";
//    file.write((char*)&userdata, sizeof(userdata));
//    file.close();
//    cout << "Аккаунт успешно создан!" << endl;
//}

