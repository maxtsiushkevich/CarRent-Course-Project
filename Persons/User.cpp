#include "User.h"
#include "Userdata.h"
#include <fstream>
#include <iostream>

using namespace std;

User :: User()
{ }

void User :: SetInfo()
{
    // добавить номер паспорта
    Person::SetInfo();
    Userdata userdata(id);
    userdata.SetInfo(2);
    strcpy(status, "Classic");
    count = 0;
    cout << "Введите номер телефона в формате <<КОД CТРАНЫ-ХХХХХХХХХХ>>: " << endl;
    fflush(stdin);
    fgets(phoneNumber, 20, stdin);
    phoneNumber[strcspn(phoneNumber, "\n")] = '\0';

    cout << "Введите страну проживания: " << endl;
    fflush(stdin);
    fgets(adress.country, 60, stdin);
    adress.country[strcspn(adress.country, "\n")] = '\0';

    cout << "Введите город проживания: " << endl;
    fflush(stdin);
    fgets(adress.city, 60, stdin);
    adress.city[strcspn(adress.city, "\n")] = '\0';

    cout << "Введите улицу: " << endl;
    fflush(stdin);
    fgets(adress.street, 60, stdin);
    adress.street[strcspn(adress.street, "\n")] = '\0';

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