#include "User.h"
#include "Userdata.h"
#include <fstream>
#include <iostream>

using namespace std;

User :: User()
{
    Userdata user(id, 2);
    status.reserve(10);
    status = "Classic";
    count = 0;
    cout << "Введите номер телефона в формате <<КОД CТРАНЫ-ХХХХХХХХХХ>>: " << endl;
    fflush(stdin);
    getline (cin, phoneNumber);
    while (phoneNumber.size() < 12 || phoneNumber.size() > 15)
    {
        cout << "Неверный ввод! Попробуйте еще раз: " << endl;
        getline (cin, phoneNumber);
    }

    cout << "Введите страну проживания: " << endl;
    fflush(stdin);
    adress.country.reserve(60);
    getline(cin, adress.country);
    while (adress.country.size() > 60 || adress.country.size() == 0)
    {
        cout << "Слишком длинная запись или пустой ввод. Введите еще раз: ";
        adress.country.reserve(60);
        getline(cin, adress.country);
    }

    cout << "Введите город проживания: " << endl;
    fflush(stdin);
    adress.city.reserve(60);
    getline(cin, adress.city);
    while (adress.city.size() > 60 || adress.city.size() == 0)
    {
        cout << "Слишком длинная запись или пустой ввод. Введите еще раз: ";
        adress.city.reserve(60);
        getline(cin, adress.city);
    }

    cout << "Введите улицу: " << endl;
    fflush(stdin);
    adress.street.reserve(60);
    getline(cin, adress.street);
    while (adress.street.size() > 60 || adress.street.size() == 0)
    {
        cout << "Слишком длинная запись или пустой ввод. Введите еще раз: ";
        adress.street.reserve(60);
        getline(cin, adress.street);
    }

    cout << "Введите дом: " << endl;
    cin >> adress.house;
    while (adress.house <= 0)
    {
        cout << "Неверный ввод. Введите еще раз: ";
        cin >> adress.house;
    }

    cout << "Введите номер квартиры: " << endl;
    cin >> adress.flat;
    while (adress.flat <= 0)
    {
        cout << "Неверный ввод. Введите еще раз: ";
        cin >> adress.flat;
    }

    ofstream file;
    file.open("../Files/User.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)this, sizeof(User));
    file.close();

}