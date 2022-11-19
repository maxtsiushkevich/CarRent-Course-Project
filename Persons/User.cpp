#include "User.h"
#include "Userdata.h"
#include <fstream>
#include <iostream>

using namespace std;

User :: User()
{
    Userdata user(id, 2);
    status = "Classic";
    count = 0;
    cout << "Введите номер телефона в формате 375ХХХХХХХХХ: " << endl;
    fflush(stdin);
    getline (cin, phoneNumber);
    while (phoneNumber.size() != 12 || phoneNumber[0] != '3' || phoneNumber[1] != '7' || phoneNumber[2] != '5')
    {
        cout << "Неверный ввод! Попробуйте еще раз: " << endl;
        getline (cin, phoneNumber);
    }

    cout << "Введите страну проживания: " << endl;
    fflush(stdin);
    getline (cin, adress.country);

    cout << "Введите город проживания: " << endl;
    fflush(stdin);
    getline (cin, adress.city);

    cout << "Введите улицу: " << endl;
    fflush(stdin);
    getline (cin, adress.street);

    cout << "Введите дом: " << endl;
    cin >> adress.house;

    cout << "Введите номер квартиры: " << endl;
    cin >> adress.flat;


    ofstream file;
    file.open("../Files/User.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)this, sizeof(User));
    file.close();

}