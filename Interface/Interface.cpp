#include "Interface.h"
#include <iostream>
#include <fstream>
#include "../Persons/User.h"
#include "../Database//Database.h"
#include "Authentication.h"
#include "CarInUsage.h"
#include "UserInterface.h"
#include "../Exception/Exception.h"

using namespace std;

Interface::Interface()
{
    Database::GetFromDatabase(petrolCars);
    Database::GetFromDatabase(dieselCars);
    Database::GetFromDatabase(electricCars);
    Database::GetFromDatabase(hybridCars);

    CarInUsage tmp;
    tmp.GetCarsInUsage(carIdInUsage);

    Session::GetAllSessions(allSessions);
}

void Interface :: FirstMenu()
{
    int choice;
    while (1)
    {
        cout << "Выберите режим входа: \n"
                "1 - Администратор\n"
                "2 - Пользователь\n"
                "3 - Регистрация нового аккаунта пользователя\n"
                "4 - Завершить работу" << endl;
       while (1)
       {
           try
           {
                cin >> choice;
                if (cin.fail())
                    throw BadInputException("Введена не цифра");
                if (choice < 1 || choice > 4)
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

void Interface :: AdminMainMenu()
{
    int choice;
    while (1)
    {
        cout << "===== Личный кабинет ===== \n"
                "1 - Просмотреть базу данных пользователей\n"
                "2 - Просмотреть базу данных автомобилей\n"
                "3 - Просмотреть все заказы\n"
                "4 - Просмотреть все заказы конкретного пользователя\n"
                "5 - Просмотреть все заказы конкретного автомобиля\n"
                "6 - Добавление автомобиля\n"
                "7 - Удаление автомобиля\n"
                "8 - Выход из аккаунта\n"
                "9 - Завершить работу" << endl;
        while (1)
        {
            try
            {
                cin >> choice;
                if (cin.fail())
                    throw BadInputException("Введена не цифра");
                if (choice < 1 || choice > 9)
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
            case 1:
                this->ShowAllUsers(); break;
            case 2:
                this->ShowAllCars(); break;
            case 3:
                this->ShowAllSessions(); break;
            case 4:
                this->ShowSpecificUserSessions(); break;
            case 5:
                this->ShowSpecificCarSessions(); break;
            case 6:
                this->AddNewCar(); break;
            case 7:
                this->DeleteSpecificCar(); break;
            case 8:
                this->RefreshAllCars(); return;
            case 9:
                this->RefreshAllCars(); exit(0);
        }
    }
}

void Interface :: ShowAllUsers()
{
    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/User.bin", ios::binary);
    if (!file.is_open()) // кетч
        cout << "Error";
    int i = 0;
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    wcout << '|' << setw(10) << left << L"ID" << '|' << setw(15) << L"Фамилия" << '|' << setw(15) << L"Имя" << '|' << setw(10) << L"Возраст" << '|'
          << setw(15) << L"Баланс" << '|' << setw(15) << L"Потрачено" << '|' << setw(10) << L"Статус" << '|' << setw(15) << L"Номер телефона" << '|' << setw(15) << L"Номер паспорта" << '|' << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    while(file.read((char*)&user, sizeof(User)))
    {
        cout << '|' << setw(10) << left << user.GetID();
        wcout << '|' << setw(15) << left << user.GetName() << '|' << setw(15) << user.GetSurname() << '|' << setw(10) << user.GetAge() << '|'
        << setw(15) << user.GetCount() << '|' << setw(15) << user.GetSpendMoney() << '|' << setw(10) << user.GetStatus() << '|' << setw(15) << user.GetPhoneNumber() << '|' << setw(15) << user.GetPassportNum() << '|' << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void Interface :: ShowAllSessions()
{
    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/User.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    vector<User> users;
    while(file.read((char*)&user, sizeof(User)))
        users.push_back(user);
    if (allSessions.size() == 0)
    {
        cout << "Нет заказов!" << endl;
        return;
    }
    int i = 1;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    wcout << '|' << setw(10) << left << L"№" << '|' << setw(15) << L"Фамилия" << '|' << setw(15) << L"Имя" << '|' << setw(15) << L"Марка" << '|' << setw(15) << L"Модель" << '|'
          << setw(15) << L"Дата начала" << '|' << setw(15) << L"Дата окончания" << '|' << setw(10) << L"Стоимость" << '|' << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        for (auto it1 = allSessions.begin(); it1 != allSessions.end(); ++it1)
        {
            for (auto it2 = petrolCars.begin(); it2 != petrolCars.end(); ++it2)
            {
                if ((it2->GetID() == it1->carID) && (it->GetID() == it1->userID))
                {
                    wcout << '|' << setw(10) << left << i << '|' << setw(15) << it->GetName() << '|' << setw(15) << it->GetSurname() << '|' << setw(15) << it2->GetBrand() << '|' << setw(15)
                    << it2->GetModel() << '|';
                    cout << setw(2) << left << it1->DateFrom.day << '.' << setw(2) << it1->DateFrom.month << '.' << setw(9) << it1->DateFrom.year << '|' << setw(2) << it1->DateTo.day << '.' << setw(2) << it1->DateTo.month << '.' << setw(9) << it1->DateTo.year << '|' << setw(10) << it1->cost << '|' << endl;
                    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                    i++;
                }
            }
            for (auto it2 = dieselCars.begin(); it2 != dieselCars.end(); ++it2)
            {
                if ((it2->GetID() == it1->carID) && (it->GetID() == it1->userID))
                {
                    wcout << '|' << setw(10) << left << i << '|' << setw(15) << it->GetName() << '|' << setw(15) << it->GetSurname() << '|' << setw(15) << it2->GetBrand() << '|' << setw(15)
                          << it2->GetModel() << '|';
                    cout << setw(2) << left << it1->DateFrom.day << '.' << setw(2) << it1->DateFrom.month << '.' << setw(9) << it1->DateFrom.year << '|' << setw(2) << it1->DateTo.day << '.' << setw(2) << it1->DateTo.month << '.' << setw(9) << it1->DateTo.year << '|' << setw(10) << it1->cost << '|' << endl;
                    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                    i++;
                }
            }
            for (auto it2 = electricCars.begin(); it2 != electricCars.end(); ++it2)
            {
                if ((it2->GetID() == it1->carID) && (it->GetID() == it1->userID))
                {
                    wcout << '|' << setw(10) << left << i << '|' << setw(15) << it->GetName() << '|' << setw(15) << it->GetSurname() << '|' << setw(15) << it2->GetBrand() << '|' << setw(15)
                          << it2->GetModel() << '|';
                    cout << setw(2) << left << it1->DateFrom.day << '.' << setw(2) << it1->DateFrom.month << '.' << setw(9) << it1->DateFrom.year << '|' << setw(2) << it1->DateTo.day << '.' << setw(2) << it1->DateTo.month << '.' << setw(9) << it1->DateTo.year << '|' << setw(10)<< it1->cost << '|' << endl;
                    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                    i++;
                }
            }
            for (auto it2 = hybridCars.begin(); it2 != hybridCars.end(); ++it2)
            {
                if ((it2->GetID() == it1->carID) && (it->GetID() == it1->userID))
                {
                    wcout << '|' << setw(10) << left << i << '|' << setw(15) << it->GetName() << '|' << setw(15) << it->GetSurname() << '|' << setw(15) << it2->GetBrand() << '|' << setw(15)
                          << it2->GetModel() << '|';
                    cout << setw(2) << left << it1->DateFrom.day << '.' << setw(2) << it1->DateFrom.month << '.' << setw(9) << it1->DateFrom.year << '|' << setw(2) << it1->DateTo.day << '.' << setw(2) << it1->DateTo.month << '.' << setw(9) << it1->DateTo.year << '|' << setw(10)<< it1->cost << '|' << endl;
                    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                    i++;
                }
            }
        }
    }
}

void Interface :: ShowAllCars()
{
    cout << "----------------------------------------------------------------------------------" << endl;
    wcout << '|' << setw(10) << left << L"Номер" << '|' << setw(15) << L"Марка" << '|' << setw(15) << L"Модель" << '|'
          << setw(15) << L"Год выпуска" << '|' << setw(10) << L"Стоимость" << '|' << setw(10) << L"Удален ли" << '|' << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    for (auto it = petrolCars.begin(); it != petrolCars.end(); ++it) {
        wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15)
              << it->GetModel();
        cout << '|' << setw(15) << left << it->GetManufacturedYear() << '|' << setw(10) << left << it->GetCostPerDay()
             << '|';
        if (it->IsDelete())
            wcout << setw(10) << left << L"Да" << '|' << endl;
        else
            wcout << setw(10) << left << L"Нет" << '|' << endl;
        cout << "----------------------------------------------------------------------------------" << endl;
    }
    for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it) {
        wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15)
              << it->GetModel();
        cout << '|' << setw(15) << left << it->GetManufacturedYear() << '|' << setw(10) << left << it->GetCostPerDay()
             << '|';
        if (it->IsDelete())
            wcout << setw(10) << left << L"Да" << '|' << endl;
        else
            wcout << setw(10) << left << L"Нет" << '|' << endl;
        cout << "----------------------------------------------------------------------------------" << endl;
    }
    for (auto it = electricCars.begin(); it != electricCars.end(); ++it) {
        wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15)
              << it->GetModel();
        cout << '|' << setw(15) << left << it->GetManufacturedYear() << '|' << setw(10) << left << it->GetCostPerDay()
             << '|';
        if (it->IsDelete())
            wcout << setw(10) << left << L"Да" << '|' << endl;
        else
            wcout << setw(10) << left << L"Нет" << '|' << endl;
        cout << "----------------------------------------------------------------------------------" << endl;
    }
    for (auto it = hybridCars.begin(); it != hybridCars.end(); ++it) {
        wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15)
              << it->GetModel();
        cout << '|' << setw(15) << left << it->GetManufacturedYear() << '|' << setw(10) << left << it->GetCostPerDay()
             << '|';
        if (it->IsDelete())
            wcout << setw(10) << left << L"Да" << '|' << endl;
        else
            wcout << setw(10) << left << L"Нет" << '|' << endl;
        cout << "----------------------------------------------------------------------------------" << endl;
    }
}

void Interface :: ShowSpecificUserSessions()
{
    this->ShowAllUsers();
    int userID;
    ifstream file;
    cout << "Введите ID интересующего пользователя: ";
    while (1)
    {
        try
        {
            cin >> userID;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            break;
        }
        catch (BadInputException exp)
        {
            exp.Fix();
        }
    }
    file.open("/Users/max/Desktop/CarRent/Files/User.bin", ios::binary); // кетч
    if (!file.is_open())
        cout << "Error";
    while(file.read((char*)&user, sizeof(User)))
    {
        if (user.GetID() == userID)
        {
            this->SeeUserHistory(userID);
            return;
        }
    }
    cout << "Введен несуществующий ID" << endl;
    return;

}

void Interface ::DeleteSpecificCar()
{
    int choice;
    while (1)
    {
        this->ShowAllCars();
        cout << "Введите ID автомобиля для удаления: \n"
                "Для выхода введите '0'" << endl;
        while (1)
        {
            try
            {
                cin >> choice;
                if (cin.fail())
                    throw BadInputException("Введена не цифра");
                break;
            }
            catch (BadInputException exp)
            {
                exp.Fix();
            }
        }

        if (choice == 0)
            return;
        cout << "Для подтверждения удаления введите '1'\n"
                "Для отмены введите '0'" << endl;
        int tmp;
        while (1)
        {
            try
            {
                cin >> tmp;
                if (cin.fail())
                    throw BadInputException("Введена не цифра");
                if (tmp < 0 || tmp > 1)
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
        if (tmp == 0)
            return;

        for (auto it = petrolCars.begin(); it != petrolCars.end(); ++it)
        {
            if (it->GetID() == choice)
            {
                it->DeleteCar();
                cout << "Автомобиль успешно удален" << endl;
                return;
            }
        }
        for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
        {
            if (it->GetID() == choice)
            {
                it->DeleteCar();
                cout << "Автомобиль успешно удален" << endl;
                return;
            }
        }
        for (auto it = electricCars.begin(); it != electricCars.end(); ++it)
        {
            if (it->GetID() == choice)
            {
                it->DeleteCar();
                cout << "Автомобиль успешно удален" << endl;
                return;
            }
        }
        for (auto it = hybridCars.begin(); it != hybridCars.end(); ++it)
        {
            if (it->GetID() == choice)
            {
                it->DeleteCar();
                cout << "Автомобиль успешно удален" << endl;
                return;
            }
        }
        cout << "Введен неверный ID" << endl;
    }
}

void Interface :: RefreshAllCars()
{
    ofstream file;

    file.open("/Users/max/Desktop/CarRent/Files/PetrolCars.bin", ios::out | ios::binary | ios::trunc);
    file.close();
    for (auto it = petrolCars.begin(); it != petrolCars.end(); ++it)
        Database::AddInDatabase(*it);

    file.open("/Users/max/Desktop/CarRent/Files/DieselCars.bin", ios::out | ios::binary | ios::trunc);
    file.close();
    for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
        Database::AddInDatabase(*it);

    file.open("/Users/max/Desktop/CarRent/Files/ElectricCars.bin", ios::out | ios::binary | ios::trunc);
    file.close();
    for (auto it = electricCars.begin(); it != electricCars.end(); ++it)
        Database::AddInDatabase(*it);

    file.open("/Users/max/Desktop/CarRent/Files/HybridCars.bin", ios::out | ios::binary | ios::trunc);
    file.close();
    for (auto it = hybridCars.begin(); it != hybridCars.end(); ++it)
        Database::AddInDatabase(*it);
}

void Interface :: ShowSpecificCarSessions()
{
    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/User.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    vector<User> users;
    while(file.read((char*)&user, sizeof(User)))
        users.push_back(user);

    this->ShowAllCars();
    cout << "Введите ID интересуещего автомобиля: ";
    int carID;
    while (1)
    {
        try
        {
            cin >> carID;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            break;
        }
        catch (BadInputException exp)
        {
            exp.Fix();
        }
    }
    for (auto it = allSessions.begin(); it != allSessions.end(); ++it)
    {
        if (it->carID == carID)
            break;
        cout << "Нет заказов или введен несуществующий номер!" << endl;
        return;
    }
    int i = 0;
    cout << "---------------------------------------------------------------------------------------" << endl;
    wcout << '|' << setw(10) << left << L"№" << '|' << setw(15) << L"Фамилия" << '|' << setw(15) << L"Имя" << '|' << setw(15) << L"Дата начала" << '|' << setw(15) << L"Дата окончания" << '|' << setw(10) << L"Стоимость" << '|' << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;

    for (auto it = allSessions.begin(); it != allSessions.end(); ++it)
    {
        if (it->carID == carID)
        {
            for (auto it1 = users.begin(); it1 != users.end(); ++it1)
            {
                if (it->userID == it1->GetID())
                {
                    wcout << '|' << setw(10) << left << i << '|' << setw(15) << it1->GetName() << '|' << setw(15) << it1->GetSurname() << '|';
                    cout << setw(2) << left << it->DateFrom.day << '.' << setw(2) << it->DateFrom.month << '.' << setw(9) << it->DateFrom.year << '|' << setw(2) << it->DateTo.day << '.' << setw(2) << it->DateTo.month << '.' << setw(9) << it->DateTo.year << '|' << setw(10) << it->cost << '|' << endl;
                    cout << "---------------------------------------------------------------------------------------" << endl;
                    i++;
                }
            }
        }
    }
}

void Interface :: AddNewCar()
{
    cout << "Тип автомобиля тип для добавления\n"
            "1 - Бензиновые автомобили\n"
            "2 - Дизельные автомобили\n"
            "3 - Электрические автомобили\n"
            "4 - Гибридные автомобили\n"
            "5 - Выход в главное меню" << endl;
    int choice;
    while (1)
    {
        try
        {
            cin >> choice;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (choice < 1 || choice > 5)
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

    PetrolCar pcar;
    DieselCar dcar;
    ElectricCar ecar;
    HybridCar hcar;
    switch (choice)
    {
        case 1:
            pcar.SetInfo();
            Database::AddInDatabase(pcar);
            petrolCars.emplace_back(pcar);
            break;
        case 2:
            dcar.SetInfo();
            Database::AddInDatabase(dcar);
            dieselCars.emplace_back(dcar);
            break;
        case 3:
            ecar.SetInfo();
            Database::AddInDatabase(ecar);
            electricCars.emplace_back(ecar);
            break;
        case 4:
            hcar.SetInfo();
            Database::AddInDatabase(hcar);
            hybridCars.emplace_back(hcar);
            break;
        case 5:
            return;

    }
}
