#include "Person.h"
#include <iostream>

Person :: Person()
{
    id = 0;
    age = 18;
}

void Person :: SetInfo()
{
    cout << "Введите фамилию: ";
    fflush(stdin);
    fgetws(surname, 30, stdin);
    surname[wcscspn(surname, L"\n")] = L'\0';
    surname[0] = towupper(surname[0]);

    cout << "Введите имя: ";
    fflush(stdin);
    fgetws(name, 30, stdin);
    name[wcscspn(name, L"\n")] = L'\0';
    name[0] = towupper(name[0]);

    cout << "Введите возраст: ";
    cin >> age;
    while (age < 18 || age > 100)
    {
        cout << "Вам должно быть больше 18 лет!" << endl;
        cin >> age;
    }
}
