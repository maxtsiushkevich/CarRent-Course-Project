#ifndef CARRENT_USER_H
#define CARRENT_USER_H
#include "Person.h"

#include <string>
#include <vector>
#include <map>

using namespace std;

class User : public Person
{
private:
    wchar_t passportNum[15]; // номер паспорта
    wchar_t status[10]; // classic, silver, gold, platinum // добавить установку статуса

    // classic -0%
    // silver -5%
    // gold -10%
    // platinum -15%

    float count; // счет
    float spendMoney; // потраченные средства
    wchar_t phoneNumber[15];
    struct Adress
    {
        wchar_t country[30];
        wchar_t city[30];
        wchar_t street[30];
        int house;
        int flat;
    } adress;
public:
    User();
    ~User() = default;
    void SetInfo(); // заполнение полей класса

    void SetNewNumber(); // установка нового номера телефона
    void SetNewAdress(); // установка нового номера паспорта
    void SetNewPassport();

    void SetCount(float plus) { count += plus; } // пополнение счета
    void SetSpendMoney(float spend) { spendMoney += spend; } // изменение количества потраченных средств
    void SetStatus(wchar_t *newStatus) { wcscpy(status, newStatus); } // установка нового статуса
    wchar_t* GetPassportNum() { return passportNum; } // получение номера паспорта
    wchar_t* GetStatus() { return status; } // получение текущего статуса
    float GetCount() { return count; } // получение текущего баланса
    float GetSpendMoney() { return spendMoney; } // получение потраченных средств
    wchar_t* GetPhoneNumber() { return phoneNumber; } // получение номера телефона
    wchar_t* GetCountry() { return adress.country; } // получение страны
    wchar_t* GetCity() { return adress.city; } // получение города
    wchar_t* GetStreet() { return adress.street; } // получение улицы
    int GetHouse() { return adress.house; } // получение дома
    int GetFlat() { return adress.flat; } // получение квартиры
};


#endif //CARRENT_USER_H

