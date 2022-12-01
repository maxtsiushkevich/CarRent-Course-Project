#include "Person.h"
#include <iostream>
#include "../ID/IdGenerator.h"

Person :: Person()
{
    id = IdGenerator::GetIdForPerson();
    age = 0;
}

void Person :: SetInfo()
{
    cout << "Введите фамилию: " << endl;
    fflush(stdin);
    fgets(surname, 60, stdin);
    surname[strcspn(surname, "\n")] = '\0';

    cout << "Введите имя: " << endl;
    fflush(stdin);
    fgets(name, 60, stdin);
    name[strcspn(name, "\n")] = '\0';

    cout << "Введите возраст: ";
    cin >> age;
    while (age < 18 || age > 100)
    {
        cout << "Вам должно быть больше 18 лет!" << endl;
        cin >> age;
    }
}
