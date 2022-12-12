#include "User.h"
#include "Userdata.h"
#include <fstream>
#include <iostream>
#include "../ID/IdGenerator.h"
#include "../Exception/Exception.h"

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
    while (1)
    {
        try
        {
            fgetws(passportNum, 15, stdin);
            passportNum[wcscspn(passportNum, L"\n")] = L'\0';
            if (passportNum[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(passportNum, L" ") <= 15)
                throw SpaceException("Введена строка с пробелом");
            break;
        }
        catch (EmptyInputException exp)
        {
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (SpaceException exp)
        {
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    
    cout << "Введите номер телефона в формате <<КОД CТРАНЫ-ХХХХХХХХХХ>>: ";
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(phoneNumber, 15, stdin);
            phoneNumber[wcscspn(phoneNumber, L"\n")] = L'\0';
            if (phoneNumber[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(phoneNumber, L" ") <= 15)
                throw SpaceException("Введена строка с пробелом");
            break;
        }
        catch (EmptyInputException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (SpaceException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }

    cout << "Введите страну проживания: ";
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(adress.country, 30, stdin);
            adress.country[wcscspn(adress.country, L"\n")] = L'\0';
            if (adress.country[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(adress.country, L" ") <= 30)
                throw SpaceException("Введена строка с пробелом");
            break;
        }
        catch (EmptyInputException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (SpaceException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    adress.country[0] = towupper(adress.country[0]);

    cout << "Введите город проживания: ";
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(adress.city, 30, stdin);
            adress.city[wcscspn(adress.city, L"\n")] = L'\0';
            if (adress.city[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(adress.city, L" ") <= 30)
                throw SpaceException("Введена строка с пробелом");
            break;
        }
        catch (EmptyInputException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (SpaceException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    adress.city[0] = towupper(adress.city[0]);

    cout << "Введите улицу: ";
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(adress.street, 30, stdin);
            adress.street[wcscspn(adress.street, L"\n")] = L'\0';
            if (adress.street[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(adress.street, L" ") <= 30)
                throw SpaceException("Введена строка с пробелом");
            break;
        }
        catch (EmptyInputException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (SpaceException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    adress.street[0] = towupper(adress.street[0]);

    cout << "Введите дом: ";
    while (1)
    {
        try
        {
            cin >> adress.house;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (adress.house <= 0)
                throw Exception("Неверный ввод. ");
            break;
        }
        catch (BadInputException exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (Exception exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }

    cout << "Введите номер квартиры: ";
    while (1)
    {
        try
        {
            cin >> adress.flat;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (adress.flat <= 0)
                throw Exception("Неверный ввод. ");
            break;
        }
        catch (BadInputException exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (Exception exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
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
    while (1)
    {
        try
        {
            fgetws(tmpPhoneNumber, 15, stdin);
            tmpPhoneNumber[wcscspn(tmpPhoneNumber, L"\n")] = L'\0';
            if (tmpPhoneNumber[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(tmpPhoneNumber, L" ") <= 15)
                throw SpaceException("Введена строка с пробелом");
            break;
        }
        catch (EmptyInputException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (SpaceException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    cout << "Подтвердить изменения?\n"
            "1 - Да\n"
            "2 - Нет" << endl;
    int choice;
    while (1)
    {
        try
        {
            cin >> choice;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (choice < 1 || choice > 2)
                throw Exception("Введен неверный пункт");
            break;
        }
        catch (BadInputException exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (Exception exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
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
    while (1)
    {
        try
        {
            fgetws(country, 30, stdin);
            country[wcscspn(country, L"\n")] = L'\0';
            if (country[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(country, L" ") <= 30)
                throw SpaceException("Введена строка с пробелом");
            break;
        }
        catch (EmptyInputException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (SpaceException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    country[0] = towupper(country[0]);

    cout << "Введите город проживания: ";
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(city, 30, stdin);
            city[wcscspn(city, L"\n")] = L'\0';
            if (city[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(city, L" ") <= 30)
                throw SpaceException("Введена строка с пробелом");
            break;
        }
        catch (EmptyInputException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (SpaceException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    city[0] = towupper(city[0]);

    cout << "Введите улицу: ";
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(street, 30, stdin);
            street[wcscspn(street, L"\n")] = L'\0';
            if (street[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(street, L" ") <= 30)
                throw SpaceException("Введена строка с пробелом");
            break;
        }
        catch (EmptyInputException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (SpaceException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    street[0] = towupper(street[0]);


    cout << "Введите дом: ";
    while (1)
    {
        try
        {
            cin >> house;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (house <= 0 )
                throw Exception("Неверный ввод. ");
            break;
        }
        catch (BadInputException exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (Exception exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    cout << "Введите номер квартиры: ";
    while (1)
    {
        try
        {
            cin >> flat;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (flat <= 0 )
                throw Exception("Неверный ввод. ");
            break;
        }
        catch (BadInputException exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (Exception exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    cout << "Подтвердить изменения?\n"
            "1 - Да\n"
            "2 - Нет" << endl;
    int choice;
    while (1)
    {
        try
        {
            cin >> choice;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (choice < 1 || choice > 2)
                throw Exception("Введен неверный пункт");
            break;
        }
        catch (BadInputException exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (Exception exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
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
    while (1)
    {
        try
        {
            fgetws(tmpPassportNum, 15, stdin);
            tmpPassportNum[wcscspn(tmpPassportNum, L"\n")] = L'\0';
            if (tmpPassportNum[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(tmpPassportNum, L" ") <= 15)
                throw SpaceException("Введена строка с пробелом");
            break;
        }
        catch (EmptyInputException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (SpaceException exp)
        {

            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    
    cout << "Подтвердить изменения?\n"
            "1 - Да\n"
            "2 - Нет" << endl;
    int choice;
    while (1)
    {
        try
        {
            cin >> choice;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (choice < 1 || choice > 2)
                throw Exception("Введен неверный пункт");
            break;
        }
        catch (BadInputException exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (Exception exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    if (choice == 1)
        wcscpy(passportNum, tmpPassportNum);
    else
        return;

}