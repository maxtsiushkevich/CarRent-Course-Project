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
            if (wcscspn(surname, L" ") <= 30)
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
    surname[0] = towupper(surname[0]);

    cout << "Введите имя: ";
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(surname, 30, stdin);
            surname[wcscspn(surname, L"\n")] = L'\0';
            if (surname[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(surname, L" ") <= 30)
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
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (Exception exp)
        {
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
}
