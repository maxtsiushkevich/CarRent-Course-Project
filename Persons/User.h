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
    bool isBlocked;
    wchar_t passportNum[30];
    wchar_t status[10]; // classic, silver, gold, platinum // добавить установку статуса

    // classic -0%
    // silver -5%
    // gold -10%
    // platinum -15%

    float count; // счет
    float spendMoney;
    wchar_t phoneNumber[20];
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
    void SetInfo();
    void SetNewNumber();
    void SetNewAdress();
    void SetCount(int plus) { count += plus; }
    void SetSpendMoney(int spend) { spendMoney += spend; }
    //void SetStatus();
    wchar_t* CheckStatus() { return status; }
    wchar_t* GetPassportNum() { return passportNum; }
    wchar_t* GetStatus() { return status; }
    float GetCount() { return count; }
    float GetSpendMoney() { return spendMoney; }
    wchar_t* GetPhoneNumber() { return phoneNumber; }
    wchar_t* GetCountry() { return adress.country; }
    wchar_t* GetCity() { return adress.city; }
    wchar_t* GetStreet() { return adress.street; }
    int GetHouse() { return adress.house; }
    int GetFlat() { return adress.flat; }
};


#endif //CARRENT_USER_H

