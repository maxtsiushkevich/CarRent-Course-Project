#ifndef CARRENT_USERINTERFACE_H
#define CARRENT_USERINTERFACE_H
#include "Interface.h"
#include <iostream>
#include "../Exception/Exception.h"
#include <FLOAT.H>
using namespace std;

void Interface :: UserMainMenu()
{
    int choice;
    while (1)
    {
        cout << "===== Личный кабинет ===== \n"
                "1 - Информация об аккаунте\n"
                "2 - Автомобили для заказа\n"
                "3 - История поездок\n"
                "4 - Пополнение счета\n"
                "5 - Настройка аккаунта\n"
                "6 - Выйти из аккаунта\n"
                "7 - Завершить работу" << endl;
        while (1)
        {
            try
            {
                cin >> choice;
                if (cin.fail())
                    throw BadInputException("Введена не цифра");
                if (choice < 1 || choice > 7)
                    throw Exception("Введен неверный пункт");
                break;
            }
            catch (BadInputException exp)
            {
                cin.clear();
                cin.ignore();
                fflush(stdin);
                exp.Show();
                cout << "Введите еще раз: ";
            }
            catch (Exception exp)
            {
                cin.clear();
                cin.ignore();
                fflush(stdin);
                exp.Show();
                cout << "Введите еще раз: ";
            }
        }
        switch (choice)
        {
            case 1:
                this->UserAccountInfo(); break;
            case 2:
                this->SeeCars(); break;
            case 3:
                this->SeeUserHistory(user.GetID()); break;
            case 4:
                this->AddCount(); break;
            case 5:
                this->SetAccountSettings(); break;
            case 6:
                this->RefreshUserInFile(); return;
            case 7:
                this->RefreshUserInFile(); exit(0); // сохранять измененный объект юзера, заменяя его в файле
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

void Interface :: SeeCars()
{
    while (1)
    {
        int choice;
        cout << "Какой тип автомобилей вас интересует?\n"
                "1 - Бензиновые автомобили\n"
                "2 - Дизельные автомобили\n"
                "3 - Электрические автомобили\n"
                "4 - Гибридные автомобили\n"
                "5 - Выход в главное меню" << endl;
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
                cin.clear();
                cin.ignore();
                fflush(stdin);
                exp.Show();
                cout << "Введите еще раз: ";
            }
            catch (Exception exp)
            {
                cin.clear();
                cin.ignore();
                fflush(stdin);
                exp.Show();
                cout << "Введите еще раз: ";
            }
        }
        if (choice == 5)
            return;
        while (1)
        {
            if (this->ShowCarsForChoosing(choice))
            {
                cout << "1 - Выход в меню пользователя\n"
                        "2 - Выбор автомобиля\n"
                        "3 - Просмотр подробной информации об автомобиле\n"
                        "4 - Выбор в другого типа автомобилей" << endl;
            } else
                return;
            int tmp;
            while (1)
            {
                try
                {
                    cin >> tmp;
                    if (cin.fail())
                        throw BadInputException("Введена не цифра");
                    if (tmp < 0 || tmp > 4)
                        throw Exception("Введен неверный пункт");
                    break;
                }
                catch (BadInputException exp)
                {
                    cin.clear();
                    cin.ignore();
                    fflush(stdin);
                    exp.Show();
                    cout << "Введите еще раз: ";
                }
                catch (Exception exp)
                {
                    cin.clear();
                    cin.ignore();
                    fflush(stdin);
                    exp.Show();
                    cout << "Введите еще раз: ";
                }
            }
            if (tmp == 4)
                break;
            switch (tmp)
            {
                case 1:
                    return;
                case 2:
                    this->CarOrder(choice);
                    return;
                case 3:
                    int id;
                    cout << "Введите номер автомобиля для просмотра: ";
                    cin >> id;
                    this->ShowDetailedInfo(choice, id); // логика как и в case 2
                    break;
            }
        }
    }
}

bool Interface :: ShowCarsForChoosing(int choice)
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
                  << setw(15) << L"Год выпуска" << '|' << setw(10) << L"Стоимость" << '|' << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            for (auto it = petrolCars.begin(); it != petrolCars.end(); ++it)
            {
                if (it->IsDelete())
                    continue;
                wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15) << it->GetModel();
                cout << '|' << setw(15) << left << it->GetManufacturedYear() << '|' << setw(10) << left << it->GetCostPerDay() << '|' << endl;
                cout << "-----------------------------------------------------------------------" << endl;
            }
            break;
        case 2:
            if (dieselCars.empty())
            {
                cout << "Нет доступных автомобилей!" << endl;
                return false;
            }
            cout << "-----------------------------------------------------------------------" << endl;
            wcout << '|' << setw(10) << left << L"Номер" << '|' << setw(15) << L"Марка" << '|' << setw(15) << L"Модель" << '|'
                  << setw(15) << L"Год выпуска" << '|' << setw(10) << L"Стоимость" << '|' << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
            {
                if (it->IsDelete())
                    continue;
                wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15) << it->GetModel();
                cout << '|' << setw(15) << left << it->GetManufacturedYear() << '|' << setw(10) << left << it->GetCostPerDay() << '|' << endl;
                cout << "-----------------------------------------------------------------------" << endl;
            }
            break;
        case 3:
            if (electricCars.empty())
            {
                cout << "Нет доступных автомобилей!" << endl;
                return false;
            }
            cout << "-----------------------------------------------------------------------" << endl;
            wcout << '|' << setw(10) << left << L"Номер" << '|' << setw(15) << L"Марка" << '|' << setw(15) << L"Модель" << '|'
                  << setw(15) << L"Год выпуска" << '|' << setw(10) << L"Стоимость" << '|' << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            for (auto it = electricCars.begin(); it != electricCars.end(); ++it)
            {
                if (it->IsDelete())
                    continue;
                wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|'
                      << setw(15) << it->GetModel();
                cout << '|' << setw(15) << left << it->GetManufacturedYear() << '|' << setw(10) << left << it->GetCostPerDay() << '|'  << endl;
                cout << "-----------------------------------------------------------------------" << endl;
            }
            break;
        case 4:
            if (hybridCars.empty())
            {
                cout << "Нет доступных автомобилей!" << endl;
                return false;
            }
            cout << "-----------------------------------------------------------------------" << endl;
            wcout << '|' << setw(10) << left << L"Номер" << '|' << setw(15) << L"Марка" << '|' << setw(15) << L"Модель" << '|'
                  << setw(15) << L"Год выпуска" << '|' << setw(10) << L"Стоимость" << '|' << endl;
            cout << "-----------------------------------------------------------------------" << endl;
            for (auto it = hybridCars.begin(); it != hybridCars.end(); ++it)
            {
                if (it->IsDelete())
                    continue;
                wcout << '|' << setw(10) << left << it->GetID() << '|' << setw(15) << it->GetBrand() << '|' << setw(15) << it->GetModel();
                cout << '|' << setw(15) << left << it->GetManufacturedYear() << '|' << setw(10) << left << it->GetCostPerDay() << '|' << endl;
                cout << "-----------------------------------------------------------------------" << endl;
            }
            break;
    }
    return true;
}

void Interface :: CarOrder(int choice)
{
    cout << "Введите номер желаемого автомобиля: " << endl;
    int carId;
    int tmp;
    while (1)
    {
        try
        {
            cin >> carId;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            break;
        }
        catch (BadInputException exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    sort(carIdInUsage.begin(), carIdInUsage.end());
    // проверяем, доступен ли этот автомобиль
    if (binary_search(carIdInUsage.begin(), carIdInUsage.end(), carId) )
    {
        cout << "К сожалению, данный автомобиль на данный момент недоступен!\n"
                "Для ввода другого номера введите '1'\n"
                "Для выхода в меню введите '2'" << endl;
        while (1)
        {
            try
            {
                cin >> tmp;
                if (cin.fail())
                    throw BadInputException("Введена не цифра");
                if (tmp < 1 || tmp > 2)
                    throw Exception("Введен неверный пункт");
                break;
            }
            catch (BadInputException exp)
            {
                cin.clear();
                cin.ignore();
                fflush(stdin);
                exp.Show();
                cout << "Введите еще раз: ";
            }
            catch (Exception exp)
            {
                cin.clear();
                cin.ignore();
                fflush(stdin);
                exp.Show();
                cout << "Введите еще раз: ";
            }
        }
        if (tmp == 1)
        {
            this->ShowCarsForChoosing(choice);
            cout << "Введите номер желаемого автомобиля: " << endl;
            cin >> carId;
        }
        else
            return;
    }
    while(!newSession.CreateSession(user.GetID(), carId, FindCost(choice, carId), user))
    {
        cout << "Желаете продолжить?\n"
                "Для выбора другого автомобиля введите '1'\n"
                "Для выхода в меню введите '2'" << endl;
        while (1)
        {
            try
            {
                cin >> tmp;
                if (cin.fail())
                    throw BadInputException("Введена не цифра");
                if (tmp < 1 || tmp > 2)
                    throw Exception("Введен неверный пункт");
                break;
            }
            catch (BadInputException exp)
            {
                cin.clear();
                cin.ignore();
                fflush(stdin);
                exp.Show();
                cout << "Введите еще раз: ";
            }
            catch (Exception exp)
            {
                cin.clear();
                cin.ignore();
                fflush(stdin);
                exp.Show();
                cout << "Введите еще раз: ";
            }
        }
        if (tmp == 1)
        {
            this->ShowCarsForChoosing(choice);
            cout << "Введите номер желаемого автомобиля: " << endl;
            cin >> carId;
        }
        else
            return;
    }
    carIdInUsage.push_back(carId);
    allSessions.push_back(newSession);
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
}

void Interface :: ShowDetailedInfo(int choice, int id)
{
    switch (choice)
    {
        case 1:
            for (auto it = petrolCars.begin(); it != petrolCars.end(); ++it)
            {
                if (it->IsDelete())
                    break;
                if (it->GetID() == id)
                {
                    wcout << L"Марка: " << it->GetBrand() << endl;
                    wcout << L"Модель: " << it->GetModel() << endl;
                    wcout << L"Тип кузова: " << it->GetBodyType() << endl;
                    cout << "Год выпуска: " << it->GetManufacturedYear() << endl;
                    wcout << L"Тип трансмиссии: " << it->GetTransmissionType() << endl;
                    cout << "\nКоличество мест: " << it->GetNumberOfSeats() << endl;
                    wcout << L"Материал и цвет салона: " << it->GetInteriorMaterial() << ',' << it->GetInteriorColor() << endl;
                    wcout << L"Цвет автомобиля: " << it->GetColor() << endl;
                    cout << "Лошадиных сил: " << it->GetHorsepower() << " л.с." << endl;
                    cout << "Разгон до 100 км/ч: " << it->GetTo100() << " с." << endl;
                    cout << "Максимальная скорость: " << it->GetMaxSpeed() << " км/ч" << endl;
                    cout << "Объем двигателя: " << it->GetVolume() << " л." << endl;
                    cout << "Расход на 100 км: " << it->GetConsumption() << " л." << endl;
                    cout << "Минимальный тип бензина: " << it->GetPetrolType() << endl;
                    cout << "Стоимость аренды на день без учета скидок: " << it->GetCostPerDay() << " BYN"  << endl;
                    cout << "Стоимость аренды на неделю без учета скидок: " << it->GetCostPerDay()*6 << " BYN"  << endl;
                    cout << "Стоимость аренды на месяц без учета скидок: " << it->GetCostPerDay()*26 << " BYN"  << endl;
                    return;
                }
            }
            cout << "Введен неверный ID" << endl;
            break;
        case 2:
            for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
            {
                if (it->IsDelete())
                    break;
                if (it->GetID() == id)
                {
                    wcout << L"Марка: " << it->GetBrand() << endl;
                    wcout << L"Модель: " << it->GetModel() << endl;
                    wcout << L"Тип кузова: " << it->GetBodyType() << endl;
                    cout << "Год выпуска: " << it->GetManufacturedYear() << endl;
                    wcout << L"Тип трансмиссии: " << it->GetTransmissionType() << endl;
                    cout << "Количество мест: " << it->GetNumberOfSeats() << endl;
                    wcout << L"Материал и цвет салона: " << it->GetInteriorMaterial() << ", " << it->GetInteriorColor() << endl;
                    wcout << L"Цвет автомобиля: " << it->GetColor() << endl;
                    cout << "Лошадиных сил: " << it->GetHorsepower() << " л.с." << endl;
                    cout << "Разгон до 100 км/ч: " << it->GetTo100() << " с." << endl;
                    cout << "Максимальная скорость: " << it->GetMaxSpeed() << " км/ч" << endl;
                    cout << "Объем двигателя: " << it->GetVolume() << " л." << endl;
                    cout << "Расход на 100 км: " << it->GetConsumption() << " л." << endl;
                    cout << "Стоимость аренды на день без учета скидок: " << it->GetCostPerDay() << " BYN" << endl;
                    cout << "Стоимость аренды на неделю без учета скидок: " << it->GetCostPerDay()*6 << " BYN"  << endl;
                    cout << "Стоимость аренды на месяц без учета скидок: " << it->GetCostPerDay()*26 << " BYN"  << endl;
                    return;
                }
            }
            cout << "Введен неdерный ID" << endl;
            break;
        case 3:

            for (auto it = electricCars.begin(); it != electricCars.end(); ++it)
            {
                if (it->IsDelete())
                    break;
                if (it->GetID() == id)
                {
                    wcout << L"Марка: " << it->GetBrand() << endl;
                    wcout << L"Модель: " << it->GetModel() << endl;
                    wcout << L"Тип кузова: " << it->GetBodyType() << endl;
                    cout << "Год выпуска: " << it->GetManufacturedYear() << endl;
                    wcout << L"Тип трансмиссии: " << it->GetTransmissionType() << endl;
                    cout << "Количество мест: " << it->GetNumberOfSeats() << endl;
                    wcout << L"Материал и цвет салона: " << it->GetInteriorMaterial() << ", " << it->GetInteriorColor() << endl;
                    wcout << L"Цвет автомобиля: " << it->GetColor() << endl;
                    cout << "Лошадиных сил: " << it->GetHorsepower() << " л.с." << endl;
                    cout << "Разгон до 100 км/ч: " << it->GetTo100() << " с." << endl;
                    cout << "Максимальная скорость: " << it->GetMaxSpeed() << " км/ч" << endl;
                    cout << "Объем батареи: " << it->GetMaxSpeed() << " кВт/ч" << endl;
                    cout << "Стоимость аренды на день без учета скидок: " << it->GetCostPerDay() << " BYN" << endl;
                    cout << "Стоимость аренды на неделю без учета скидок: " << it->GetCostPerDay()*6 << " BYN"  << endl;
                    cout << "Стоимость аренды на месяц без учета скидок: " << it->GetCostPerDay()*26 << " BYN"  << endl;
                    return;
                }
            }
            cout << "Введен неdерный ID" << endl;
            break;
        case 4:
            for (auto it = hybridCars.begin(); it != hybridCars.end(); ++it)
            {
                if (it->IsDelete())
                    break;
                if (it->GetID() == id)
                {
                    wcout << L"Марка: " << it->GetBrand() << endl;
                    wcout << L"Модель: " << it->GetModel() << endl;
                    wcout << L"Тип кузова: " << it->GetBodyType() << endl;
                    cout << "Год выпуска: " << it->GetManufacturedYear() << endl;
                    wcout << L"Тип трансмиссии: " << it->GetTransmissionType() << endl;
                    cout << "Количество мест: " << it->GetNumberOfSeats() << endl;
                    wcout << L"Материал и цвет салона: " << it->GetInteriorMaterial() << ", " << it->GetInteriorColor() << endl;
                    wcout << L"Цвет автомобиля: " << it->GetColor() << endl;
                    wcout << L"Тип топлива: " << it->GetFuelType() << endl;
                    cout << "Лошадиных сил: " << it->GetHorsepower() << " л.с." << endl;
                    cout << "Разгон до 100 км/ч: " << it->GetTo100() << " с." << endl;
                    cout << "Максимальная скорость: " << it->GetMaxSpeed() << " км/ч" << endl;
                    cout << "Объем двигателя: " << it->GetVolume() << " л." << endl;
                    cout << "Расход на 100 км: " << it->GetConsumption() << " л." << endl;
                    cout << "Объем батареи: " << it->GetMaxSpeed() << " кВт/ч" << endl;
                    cout << "Стоимость аренды на день без учета скидок: " << it->GetCostPerDay() << " BYN" << endl;
                    cout << "Стоимость аренды на неделю без учета скидок: " << it->GetCostPerDay()*6 << " BYN"  << endl;
                    cout << "Стоимость аренды на месяц без учета скидок: " << it->GetCostPerDay()*26 << " BYN"  << endl;
                    return;
                }
            }
            cout << "Введен неdерный ID" << endl;
            break;
    }
}

void Interface :: SeeUserHistory(int userID)
{
    int i=0;
//    if (allSessions.empty())
//    {
//        cout << "Нет заказов!" << endl;
//        return;
//    }
//
//    for (auto it = allSessions.begin(); it != allSessions.end(); ++it)
//    {
//        if (it->userID == userID)
//            break;
//        cout << "Нет заказов!" << endl;
//        return;
//    }

    cout << "---------------------------------------------------------------------------------------" << endl;
    wcout << '|' << setw(10) << left << L"Номер" << '|' << setw(15) << L"Марка" << '|' << setw(15) << L"Модель" << '|' << setw(15) << L"Дата начала" << '|'
          << setw(15) << L"Дата окончания" << '|' << setw(10) << L"Стоимость" << '|' << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    for (auto it = allSessions.begin(); it != allSessions.end(); ++it)
    {
        i++;
        for (auto it1 = petrolCars.begin(); it1 != petrolCars.end(); ++it1)
        {
            if ((it1->GetID() == it->carID) && (userID == it->userID)) {
                wcout << '|' << setw(10) << left << i << '|' << setw(15) << it1->GetBrand() << '|' << setw(15)
                      << it1->GetModel() << '|';
                cout << setw(2) << left << it->DateFrom.day << '.' << setw(2) << it->DateFrom.month << '.' << setw(9) << it->DateFrom.year << '|' << setw(2) << it->DateTo.day << '.' << setw(2) << it->DateTo.month << '.' << setw(9) << it->DateTo.year << '|' << setw(10) << it->cost << '|' << endl;
                cout << "---------------------------------------------------------------------------------------" << endl;
            }
        }
        for (auto it1 = dieselCars.begin(); it1 != dieselCars.end(); ++it1)
        {
            if ((it1->GetID() == it->carID) && (userID == it->userID)) {
                wcout << '|' << setw(10) << left << i << '|' << setw(15) << it1->GetBrand() << '|' << setw(15)
                      << it1->GetModel() << '|';
                cout << setw(2) << left << it->DateFrom.day << '.' << setw(2) << it->DateFrom.month << '.' << setw(9) << it->DateFrom.year << '|' << setw(2) << it->DateTo.day << '.' << setw(2) << it->DateTo.month << '.' << setw(9) << it->DateTo.year << '|' << setw(10) << it->cost << '|' << endl;
                cout << "---------------------------------------------------------------------------------------" << endl;
            }
        }
        for (auto it1 = electricCars.begin(); it1 != electricCars.end(); ++it1)
        {
            if ((it1->GetID() == it->carID) && (userID == it->userID)) {
                wcout << '|' << setw(10) << left << i << '|' << setw(15) << it1->GetBrand() << '|' << setw(15)
                      << it1->GetModel() << '|';
                cout << setw(2) << left << it->DateFrom.day << '.' << setw(2) << it->DateFrom.month << '.' << setw(9) << it->DateFrom.year << '|' << setw(2) << it->DateTo.day << '.' << setw(2) << it->DateTo.month << '.' << setw(9) << it->DateTo.year << '|' << setw(10)<< it->cost << '|' << endl;
                cout << "---------------------------------------------------------------------------------------" << endl;
            }
        }
        for (auto it1 = hybridCars.begin(); it1 != hybridCars.end(); ++it1)
        {
            if ((it1->GetID() == it->carID) && (userID == it->userID)) {
                wcout << '|' << setw(10) << left << i << '|' << setw(15) << it1->GetBrand() << '|' << setw(15)
                      << it1->GetModel() << '|';
                cout << setw(2) << left << it->DateFrom.day << '.' << setw(2) << it->DateFrom.month << '.' << setw(9) << it->DateFrom.year << '|' << setw(2) << it->DateTo.day << '.' << setw(2) << it->DateTo.month << '.' << setw(9) << it->DateTo.year << '|' << setw(10)<< it->cost << '|' << endl;
                cout << "---------------------------------------------------------------------------------------" << endl;
            }
        }
    }
}

void Interface :: AddCount()
{
    cout << "Введите сумму для пополнения" << endl;
    float plus;
    while (1)
    {
        try
        {
            cin >> plus;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (plus > FLT_MAX)
                throw OverflowException("Введено слишком большое значение");
            break;
        }
        catch (BadInputException exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
        catch (OverflowException exp)
        {
            cin.clear();
            cin.ignore();
            fflush(stdin);
            exp.Show();
            cout << "Введите еще раз: ";
        }
    }
    user.SetCount(plus);
}

void Interface :: SetAccountSettings()
{
    while (1)
    {
        cout << "1 - Cменить номер паспорта\n"
                "2 - Сменить номер телефона\n"
                "3 - Сменить адрес\n"
                "4 - Сменить логин\n"
                "5 - Сменить пароль\n"
                "6 - Выход в меню" << endl; // смена логина и пароля
        int choice;
        while (1)
        {
            try
            {
                cin >> choice;
                if (cin.fail())
                    throw BadInputException("Введена не цифра");
                if (choice < 1 || choice > 6)
                    throw Exception("Введен неверный пункт");
                break;
            }
            catch (BadInputException exp)
            {
                cin.clear();
                cin.ignore();
                fflush(stdin);
                exp.Show();
                cout << "Введите еще раз: ";
            }
            catch (Exception exp)
            {
                cin.clear();
                cin.ignore();
                fflush(stdin);
                exp.Show();
                cout << "Введите еще раз: ";
            }
        }
        switch (choice)
        {
            case 1:
                user.SetNewPassport(); break;
            case 2:
                user.SetNewNumber(); break;
            case 3:
                user.SetNewAdress(); break;
            case 4:
                Userdata::ChangeLogin(user.GetID()); break;
            case 5:
                Userdata::ChangePassword(user.GetID()); break;
            case 6:
                return;
        }
    }
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

#endif