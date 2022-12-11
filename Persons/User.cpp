#include "User.h"
#include "Userdata.h"
#include <fstream>
#include <iostream>
#include "../ID/IdGenerator.h"

using namespace std;

User :: User()
{
    count = 0.0;
    spendMoney = 0.0;
}

void User :: SetInfo()
{
    id = IdGenerator::GetIdForPerson();
    Person::SetInfo();
    Userdata userdata(id);
    userdata.SetInfo(2);
    wcscpy(status, L"Classic");
    count = 0;

    cout << "Введите номер паспорта: ";
    fflush(stdin);
    fgetws(passportNum, 15, stdin);
    passportNum[wcscspn(passportNum, L"\n")] = L'\0';


    cout << "Введите номер телефона в формате <<КОД CТРАНЫ-ХХХХХХХХХХ>>: ";
    fflush(stdin);
    fgetws(phoneNumber, 15, stdin);
    phoneNumber[wcscspn(phoneNumber, L"\n")] = L'\0';


    cout << "Введите страну проживания: ";
    fflush(stdin);
    fgetws(adress.country, 30, stdin);
    adress.country[wcscspn(adress.country, L"\n")] = L'\0';
    adress.country[0] = towupper(adress.country[0]);

    cout << "Введите город проживания: ";
    fflush(stdin);
    fgetws(adress.city, 30, stdin);
    adress.city[wcscspn(adress.city, L"\n")] = L'\0';
    adress.city[0] = towupper(adress.city[0]);

    cout << "Введите улицу: ";
    fflush(stdin);
    fgetws(adress.street, 30, stdin);
    adress.street[wcscspn(adress.street, L"\n")] = L'\0';
    adress.street[0] = towupper(adress.street[0]);

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

    cout << "Аккаунт успешно создан!" << endl;
    ofstream file;
    file.open("../Files/User.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)this, sizeof(User));
    file.close();
}

void User :: SetNewNumber()
{
    cout << "Введите номер телефона: ";
    fflush(stdin);
    wchar_t tmpPhoneNumber[15];
    fgetws(tmpPhoneNumber, 15, stdin);
    phoneNumber[wcscspn(tmpPhoneNumber, L"\n")] = L'\0';

    cout << "Подтвердить изменения?\n"
            "1 - Да\n"
            "2 - Нет" << endl;
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 2)
    {
        cout << "Ошибка. Введите еще раз:";
        cin >> choice;
    }
    if (choice == 1)
        wcscpy(phoneNumber, tmpPhoneNumber);
    else
        return;
}

void User :: SetNewAdress()
{
    wchar_t country[30], city[30], street[30];
    int house, flat;
    cout << "Введите страну проживания: ";
    fflush(stdin);
    fgetws(country, 30, stdin);
    adress.country[wcscspn(country, L"\n")] = L'\0';
    adress.country[0] = towupper(adress.country[0]);

    cout << "Введите город проживания: ";
    fflush(stdin);
    fgetws(city, 30, stdin);
    adress.city[wcscspn(city, L"\n")] = L'\0';
    adress.city[0] = towupper(adress.city[0]);

    cout << "Введите улицу: ";
    fflush(stdin);
    fgetws(street, 30, stdin);
    adress.street[wcscspn(street, L"\n")] = L'\0';
    adress.street[0] = towupper(adress.street[0]);


    cout << "Введите дом: ";
    cin >> house;
    while (house <= 0)
    {
        cout << "Неверный ввод. Введите еще раз: ";
        cin >> house;
    }

    cout << "Введите номер квартиры: ";
    cin >> flat;
    while (flat <= 0)
    {
        cout << "Неверный ввод. Введите еще раз: ";
        cin >> flat;
    }

    cout << "Подтвердить изменения?\n"
            "1 - Да\n"
            "2 - Нет" << endl;
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 2)
    {
        cout << "Ошибка. Введите еще раз:";
        cin >> choice;
    }
    if (choice == 1)
    {
        wcscpy(adress.country, country);
        wcscpy(adress.city, city);
        wcscpy(adress.street, street);
        adress.house = house;
        adress.flat = flat;
    }
    else
        return;
}

void User :: SetNewPassport()
{
    wchar_t tmpPassportNum[15];
    cout << "Введите новый номер паспорта: ";
    fflush(stdin);
    fgetws(tmpPassportNum, 15, stdin);
    passportNum[wcscspn(tmpPassportNum, L"\n")] = L'\0';

    cout << "Подтвердить изменения?\n"
            "1 - Да\n"
            "2 - Нет" << endl;
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 2)
    {
        cout << "Ошибка. Введите еще раз:";
        cin >> choice;
    }
    if (choice == 1)
        wcscpy(passportNum, tmpPassportNum);
    else
        return;

}