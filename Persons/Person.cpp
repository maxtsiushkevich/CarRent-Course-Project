#include "Person.h"
#include <iostream>
#include "../ID/IdGenerator.h"

Person :: Person()
{
    id = IdGenerator::GetIdForPerson();
    cout << "Введите фамилию: " << endl;
    fflush(stdin);
    name.reserve(60);
    getline(cin, surname);
    while (surname.size() > 60 || surname.size() == 0)
    {
        cout << "Слишком длинная запись или пустой ввод. Введите еще раз: ";
        surname.reserve(60);
        getline(cin, surname);
    }


    cout << "Введите имя: " << endl;
    fflush(stdin);
    name.reserve(60);
    getline(cin, name);
    while (name.size() > 60 || name.size() == 0)
    {
        cout << "Слишком длинная запись или пустой ввод. Введите еще раз: ";
        name.reserve(60);
        getline(cin, name);
    }

    cout << "Введите возраст: ";
    cin >> age;
    while (age < 18)
    {
        cout << "Вам должно быть больше 18 лет!" << endl;
        cin >> age;
    }
}

Person :: Person(int mode) { }

Person :: ~Person() { }