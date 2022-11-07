#include "Person.h"
#include <iostream>
#include "../ID/IdGenerator.h"

Person :: Person()
{
    id = IdGenerator::GetIdForPerson();
    cout << "Введите фамилию и имя: " << endl;
    fflush(stdin);
    getline(cin, name);
    cout << "Введите возраст: ";
    cin >> age;
    while (age < 18)
    {
        cout << "Вам должно быть больше 18 лет!" << endl;
        cin >> age;
    }
}

Person :: Person(int a) { }

Person :: ~Person() { }