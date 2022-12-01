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
    char status[10]; // classic, silver, gold, platinum
    float count; // счет
    char phoneNumber[20];
    struct Adress
    {
        char country[60];
        char city[60];
        char street[60];
        int house;
        int flat;
    } adress;
public:
    User();
    ~User() = default;
    void SetInfo();
};


#endif //CARRENT_USER_H

