#include "Car.h"
#include <iostream>
#include <fstream>
#include "CarBrands.h"
#include "../ID/IdGenerator.h"
#include "../Exception/Exception.h"

using namespace std;

Car :: Car()
{
    id = 0; // присваем ID
    deleteMark = false;
    manufacturedYear = 0;
    numberOfSeats = 0;
    horsepower = 0;
    to100 = 0.0;
    maxSpeed = 0;
    costPerDay = 0;
}

void Car :: SetInfo()
{
    int choice;
    id = IdGenerator::GetIdForCar(); // присваем ID
    CarBrands carinfo;


    carinfo.GetCarBrands(); // выводит список марок
    cout << "Выберите марку автомобиля: " << endl; // выбор
    while (1)
    {
        try
        {
            cin >> choice;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (choice < 1 || choice > 30)
                throw Exception("Введен неверный пункт");
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

    wcscpy(brand, carinfo.GetBrand(choice).c_str());
    wcscpy(country, carinfo.GetCountry(choice).c_str());

    cout << "Модель автомобиля: " << endl;
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(model, 30, stdin);
            model[wcscspn(model, L"\n")] = L'\0';
            if (model[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(model, L" ") < wcscspn(model, L"\0"))
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
    model[0] = towupper(model[0]);

    cout << "Тип кузова: " << endl;
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(bodyType, 30, stdin);
            bodyType[wcscspn(bodyType, L"\n")] = L'\0';
            if (bodyType[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(bodyType, L" ") < wcscspn(bodyType, L"\0"))
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
    bodyType[0] = towupper(bodyType[0]);

    cout << "Год выпуска автомобиля: " << endl;
    while (1)
    {
        try
        {
            cin >> manufacturedYear;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (manufacturedYear < 1930 || manufacturedYear > 2022)
                throw Exception("Неверное значене");
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

    cout << "Коробка передач:\n1 - Автоматическа\n2 - Механическая " << endl; // выбор из АКПП или МКПП
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
            exp.Fix();
        }
        catch (Exception exp)
        {
            exp.Fix();
        }
    }
    switch (choice)
    {
        case 1: wcscpy(transmissionType, L"АКПП\0"); break;
        case 2: wcscpy(transmissionType, L"МКПП\0"); break;
    }

    cout << "Количество мест: " << endl;
    while (1)
    {
        try
        {
            cin >> numberOfSeats;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (numberOfSeats < 2 || numberOfSeats > 7)
                throw Exception("Введен неверный пункт");
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
    cout << "Материал салона" << endl;
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(interior.material, 30, stdin);
            interior.material[wcscspn(interior.material, L"\n")] = L'\0';
            if (interior.material[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(interior.material, L" ") < wcscspn(interior.material, L"\0"))
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
    interior.material[0] = towupper(interior.material[0]);

    cout << "Цвет салона" << endl;
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(interior.color, 30, stdin);
            interior.color[wcscspn(interior.color, L"\n")] = L'\0';
            if (interior.color[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(interior.color, L" ") < wcscspn(interior.color, L"\0"))
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
    interior.color[0] = towupper(interior.color[0]);

    cout << "Цвет автомобиля" << endl;
    fflush(stdin);
    while (1)
    {
        try
        {
            fgetws(color, 30, stdin);
            color[wcscspn(color, L"\n")] = L'\0';
            if (color[0] == L'\0')
                throw EmptyInputException("Вы ничего не ввели");
            if (wcscspn(color, L" ") < wcscspn(interior.color, L"\0"))
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
    color[0] = towupper(color[0]);

    cout << "Количество лошадиных сил в двигателе: " << endl;
    while (1)
    {
        try
        {
            cin >> horsepower;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (horsepower <= 0 || horsepower > 1000)
                throw Exception("Введен неверный пункт");
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
    cout << "Разгон до 100: " << endl;
    while (1)
    {
        try
        {
            cin >> to100;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (to100 < 1.0)
                throw Exception("Введен неверный пункт");
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

    cout << "Максимальная скорость: " << endl;
    while (1)
    {
        try
        {
            cin >> maxSpeed;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (maxSpeed < 10 || maxSpeed > 500)
                throw Exception("Введен неверный пункт");
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
    cout << "Стоимость аренды на день: " << endl;
    while (1)
    {
        try
        {
            cin >> costPerDay;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (costPerDay < 0)
                throw Exception("Введен неверный пункт");
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