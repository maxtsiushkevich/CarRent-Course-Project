#include "User.h"
#include "Userdata.h"
#include <fstream>
#include <iostream>

using namespace std;

User :: User()
{
    count = 0.0;
    spendMoney = 0.0;
    isBlocked = false;
}

void User :: SetInfo()
{

    Person::SetInfo();
    Userdata userdata(id);
    userdata.SetInfo(2);
    wcscpy(status, L"Classic");
    count = 0;

    cout << "Введите номер паспорта: ";
    fflush(stdin);
    fgetws(passportNum, 30, stdin);
    passportNum[wcscspn(passportNum, L"\n")] = L'\0';

    cout << "Введите номер телефона в формате <<КОД CТРАНЫ-ХХХХХХХХХХ>>: ";
    fflush(stdin);
    fgetws(phoneNumber, 20, stdin);
    phoneNumber[wcscspn(phoneNumber, L"\n")] = L'\0';

    cout << "Введите страну проживания: ";
    fflush(stdin);
    fgetws(adress.country, 30, stdin);
    adress.country[wcscspn(adress.country, L"\n")] = L'\0';

    cout << "Введите город проживания: ";
    fflush(stdin);
    fgetws(adress.city, 30, stdin);
    adress.city[wcscspn(adress.city, L"\n")] = L'\0';

    cout << "Введите улицу: ";
    fflush(stdin);
    fgetws(adress.street, 30, stdin);
    adress.street[wcscspn(adress.street, L"\n")] = L'\0';

    cout << "Введите дом: ";
    cin >> adress.house;
    while (adress.house <= 0)
    {
        cout << "Неверный ввод. Введите еще раз: ";
        cin >> adress.house;
    }

    cout << "Введите номер квартиры: ";
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