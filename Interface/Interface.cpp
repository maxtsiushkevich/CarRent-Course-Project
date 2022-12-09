#include "Interface.h"
#include <iostream>
#include <fstream>
#include "../Persons/User.h"
#include "../Database//Database.h"
#include "Authentication.h"
#include "CarInUsage.h"
using namespace std;

Interface::Interface()
{
    Database::GetFromDatabase(petrolCars);
    Database::GetFromDatabase(dieselCars);
    Database::GetFromDatabase(electricCars);
    Database::GetFromDatabase(hybridCars);

    CarInUsage tmp;
    tmp.GetCarsInUsage(carIdInUsage);
}

void Interface :: FirstMenu()
{
    int choice;
    while (1)
    {
        cout << "Выберите режим входа: " << endl;
        cout << "1 - Администратор" << endl;
        cout << "2 - Пользователь" << endl;
        cout << "3 - Регистрация нового аккаунта пользователя" << endl;
        cout << "4 - Завершить работу" << endl;
        cin >> choice;
        while (choice < 1 || choice > 4)
        {
            cout << "Ошибка!" << endl;
            cin >> choice;
        }
        Authentication auth;
        switch (choice)
        {
            case 1:
                if (auth.AdminAuthentication(this->admin))
                    this->AdminMainMenu();
                break;
            case 2:
                if (auth.UserAuthentication(this->user))
                    this->UserMainMenu();
                break;
            case 3:
                this->Registation();
                break;
            case 4:
                exit(0);
        }
    }
}

void Interface :: Registation()
{
    user.SetInfo();
}

void Interface :: UserMainMenu()
{
    int choice;
    while (1)
    {
        cout << "===== Личный кабинет ===== " << endl;
        cout << "1 - Информация об аккаунте" << endl;
        cout << "2 - Автомобили для заказа" << endl;
        cout << "3 - История поездок" << endl;
        cout << "4 - Пополнение счета" << endl;
        cout << "5 - Настройка аккаунта" << endl;
        cout << "6 - Выйти из аккаунта" << endl;
        cout << "7 - Завершить работу" << endl;
        cin >> choice;
        while (choice < 1 || choice > 7)
        {
            cout << "Ошибка!" << endl;
            cin >> choice;
        }
        switch (choice)
        {
            case 1:
                this->UserAccountInfo();
                break;
            case 2:
                this->ChoosingCar();
                break;
            case 3:

                break;
            case 4:
                this->AddCount();
                break;
            case 5:
                break;
            case 6:
                this->RefreshUserInFile();
                return;
            case 7:
                this->RefreshUserInFile();
                exit(0); // сохранять измененный объект юзера, заменяя его в файле
        }
    }
}

void Interface :: UserAccountInfo()
{
    cout << "Имя: ";
    wcout << user.GetName() << ' ' << user.GetSurname() << endl;
    cout << "Возраст: ";
    cout << user.GetAge()<< endl;
    cout << "Баланс: ";
    cout << user.GetCount() << endl;
    cout << "Потрачено на платформе: ";
    cout << user.GetSpendMoney() << endl; // не выводит дробную часть
    cout << "Текущий статус: ";
    wcout << user.GetStatus()<< endl;
    cout << "Номер паспорта, привязанного к аккаунту: ";
    wcout << user.GetPassportNum() << endl;
    cout << "Номер телефона: ";
    wcout << user.GetPhoneNumber() << endl;
    cout << "Адрес: ";
    wcout << user.GetCountry() << ", " << user.GetCity() << ", " << user.GetStreet() << ' ' << user.GetHouse() << '-' << user.GetFlat() << endl;
}

void Interface :: AdminMainMenu()
{
    int choice;
    while (1)
    {
        cout << "===== Личный кабинет ===== " << endl;
        cout << "1 - Просмотреть базу данных пользователей" << endl;
        cout << "2 - Просмотреть базу данных автомобилей" << endl;
        cout << "3 - Просмотреть все заказы автомобилей" << endl;
        cout << "4 - Просмотреть все заказы конкретного пользователя" << endl;
        cout << "5 - Просмотреть все заказы конкретного автомобиля" << endl;
        cout << "6 - Блокировка пользователя" << endl;
        cout << "7 - Добавление автомобиля" << endl;
        cout << "8 - Удаление автомобиля" << endl;
    }
}

void Interface :: ChoosingCar()
{
    int choice;
    cout << "Какой тип автомобилей вас интересует?\n"
            "1 - Бензиновые автомобили\n"
            "2 - Дизельные автомобили\n"
            "3 - Электрические автомобили\n"
            "4 - Гибридные автомобили" << endl;
    cin >> choice;
    while (choice < 0 | choice > 4)
    {
        cout << "Ошибка. Введите еще раз:" << endl;
        cin >> choice;
    }
    if(this->ShowCars(choice))
    {
        cout << "1 - Выход в меню пользователя\n"
                "2 - Выбор автомобиля\n"
                "3 - Просмотр подробной информации об автомобиле" << endl;
    }
    else
        return;
    int tmp;
    cin >> tmp;
    while (tmp < 0 | tmp > 3)
    {
        cout << "Ошибка. Введите еще раз:" << endl;
        cin >> tmp;
    }
    switch (tmp)
    {
        case 1:
            return;
        case 2:
            cout << "Введите номер желаемого автомобиля: " << endl;
            int carId;
            cin >> carId;
            sort(carIdInUsage.begin(), carIdInUsage.end());
            // проверяем, доступен ли этот автомобиль
            if (binary_search(carIdInUsage.begin(), carIdInUsage.end(), carId))
            {
                cout << "К сожалению, данный автомобиль на данный момент недоступен!\n"
                        "Для ввода другого номера введите '1'\n"
                        "Для выхода в меню введите '2'" << endl;
                cin >> tmp;
                while (tmp < 1 || tmp > 2)
                {
                    cout << "Ошибка ввода" << endl;
                }
                if (tmp == 1)
                {
                    cout << "Введите номер желаемого автомобиля: " << endl;
                    cin >> carId;
                }
                if (tmp == 2)
                    break;
            }
            while(!newSession.CreateSession(user.GetID(), carId, FindCost(choice, carId), user))
            {
                cout << "Желаете продолжить?\n"
                        "Для выбора другого автомобиля введите '1'\n"
                        "Для выхода в меню введите '2'" << endl;
                cin >> tmp;
                while (tmp < 1 || tmp > 2)
                {
                    cout << "Ошибка ввода" << endl;
                }
                if (tmp == 1)
                {
                    cout << "Введите номер желаемого автомобиля: " << endl;
                    cin >> carId;
                }
                if (tmp == 2)
                    return;
            }
            carIdInUsage.push_back(carId);
            allSessions.push_back(newSession);
            break;
        //case 3:
        //    this->ShowDetailedInfo(); // логика как и в case 2
    }
}

bool Interface :: ShowCars(int choice)
{
    switch (choice)
    {
        case 1:
            if (petrolCars.empty())
            {
                cout << "Нет доступных автомобилей!" << endl;
                return false;
            }
            cout << "-----------------------------------------------------------------------" << endl;
            wcout << '|' << setw(10) << left << L"Номер" << '|' << setw(15) << L"Марка" << '|' << setw(15) << L"Модель" << '|'
            << setw(15) << left << L"Год выпуска" << '|' << setw(10) << left << L"Стоимость" << '|' << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            for (auto it = petrolCars.begin(); it != petrolCars.end(); ++it)
            {
                wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15) << it->GetModel();
                cout << '|' << setw(15) << left << it->GetManufacturedYear() << '|' << setw(10) << left << it->GetCostPerDay() << '|' << endl;
                cout << "-----------------------------------------------------------------------" << endl;
            }
            return true;
        case 2:
            if (dieselCars.empty())
            {
                cout << "Нет доступных автомобилей!" << endl;
                return false;
            }
            cout << "-----------------------------------------------------------------------" << endl;
            wcout << '|' << setw(10) << left << L"Номер" << '|' << setw(15) << L"Марка" << '|' << setw(15) << L"Модель" << '|'
            << setw(15) << left << L"Год выпуска" << '|' << setw(10) << left << L"Стоимость" << '|' << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
            {
                wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15) << it->GetModel();
                cout << '|' << setw(15) << left << it->GetManufacturedYear() << '|' << setw(10) << left << it->GetCostPerDay() << '|' << endl;
                cout << "-----------------------------------------------------------------------" << endl;
            }
            return true;
        case 3:
            if (electricCars.empty())
            {
                cout << "Нет доступных автомобилей!" << endl;
                return false;
            }
            cout << "-----------------------------------------------------------------------" << endl;
            wcout << '|' << setw(10) << left << L"Номер" << '|' << setw(15) << L"Марка" << '|' << setw(15) << L"Модель" << '|'
            << setw(15) << left << L"Год выпуска" << '|' << setw(10) << left << L"Стоимость" << '|' << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            for (auto it = electricCars.begin(); it != electricCars.end(); ++it)
            {
                wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|'
                << setw(15) << it->GetModel();
                cout << '|' << setw(15) << left << it->GetManufacturedYear() << '|' << setw(10) << left << it->GetCostPerDay() << '|'  << endl;
                cout << "-----------------------------------------------------------------------" << endl;
            }
            return true;
        case 4:
            if (hybridCars.empty())
            {
                cout << "Нет доступных автомобилей!" << endl;
                return false;
            }
            cout << "-----------------------------------------------------------------------" << endl;
            wcout << '|' << setw(10) << left << L"Номер" << '|' << setw(15) << L"Марка" << '|' << setw(15) << L"Модель" << '|' << setw(15) << left << L"Год выпуска" << '|' << setw(10) << left << L"Стоимость" << '|' << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            for (auto it = hybridCars.begin(); it != hybridCars.end(); ++it)
            {
                wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15) << it->GetModel();
                cout << '|' << setw(15) << left << it->GetManufacturedYear() << '|' << setw(10) << left << it->GetCostPerDay() << '|' << endl;
                cout << "-----------------------------------------------------------------------" << endl;
            }
            return true;
    }
}

int Interface :: FindCost(int choice, int carId)
{
    if (choice == 1)
    {
        for (auto it = petrolCars.begin(); it != petrolCars.end(); ++it)
        {
            if (it->GetID() == carId)
                return it->GetCostPerDay();
        }
    }
    if (choice == 2)
    {
        for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
        {
            if (it->GetID() == carId)
                return it->GetCostPerDay();
        }
    }
    if (choice == 3)
    {
        for (auto it = electricCars.begin(); it != electricCars.end(); ++it)
        {
            if (it->GetID() == carId)
                return it->GetCostPerDay();
        }
    }
    if (choice == 4)
    {
        for (auto it = hybridCars.begin(); it != hybridCars.end(); ++it)
        {
            if (it->GetID() == carId)
                return it->GetCostPerDay();
        }
    }
    return 0;
} // в шаблон

void Interface :: AddCount()
{
    cout << "Введите сумму для пополнения" << endl;
    float plus;
    cin >> plus;
    user.SetCount(plus);
}

void Interface :: RefreshUserInFile()
{
    ifstream file1; // для чтения
    ofstream file2; // для записи
    if (user.GetSpendMoney() >= 500 && user.GetSpendMoney() < 1000)
        user.SetStatus(L"Silver");
    else if (user.GetSpendMoney() >= 1000 && user.GetSpendMoney() < 2000)
        user.SetStatus(L"Gold");
    else if (user.GetSpendMoney() >= 2000)
        user.SetStatus(L"Platinum");
    file1.open("/Users/max/Desktop/CarRent/Files/User.bin", ios::binary);
    if (!file1.is_open())
        cout << "Error";
    file2.open("/Users/max/Desktop/CarRent/Files/tmp.bin", ios::binary | ios::app);
    User tmp;
    while(file1.read((char*)&tmp, sizeof(User)))
    {
        if (tmp.GetID() == user.GetID())
            file2.write((char*)&user, sizeof(User));
        else
            file2.write((char*)&tmp, sizeof(User));
    }
    file1.close();
    remove("/Users/max/Desktop/CarRent/Files/User.bin");
    file2.close();
    rename("/Users/max/Desktop/CarRent/Files/tmp.bin","/Users/max/Desktop/CarRent/Files/User.bin");
}