#include "Person.h"
#include <iostream>
#include "../Exception/Exception.h"

Person :: Person()
{
    id = 0;
    age = 18;
}

void Person :: SetInfo()
{
    cout << "Введите фамилию: ";
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(surname, 30, stdin);
            surname[wcscspn(surname, L"\n")] = L'\0';
            if (surname[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(surname, L" ") < wcscspn(surname, L"\0")) // считает до \0
                throw SpaceException("Введена строка с пробелом");
            break;
        }
        catch (EmptyInputException exp)
        {
            exp.Fix();
        }
        catch (SpaceException exp)
        {
            exp.Fix();
        }
    }
    surname[0] = towupper(surname[0]);

    cout << "Введите имя: ";
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(name, 30, stdin);
            surname[wcscspn(name, L"\n")] = L'\0';
            if (surname[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(name, L" ") < wcscspn(name, L"\0"))
                throw SpaceException("Введена строка с пробелом");
            break;
        }
        catch (EmptyInputException exp)
        {
            exp.Fix();
        }
        catch (SpaceException exp)
        {
            exp.Fix();
        }
    }
    name[0] = towupper(name[0]);

    cout << "Введите возраст: ";
    while (1)
    {
        try
        {
            cin >> age;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (age < 18 || age > 100)
                throw Exception("Вам не может быть меньше 18 и больше 100 лет!");
            break;
        }
        catch (BadInputException exp)
        {
            exp.Fix();
        }
        catch (Exception exp)
        {
            exp.Fix();
        }
    }
}
