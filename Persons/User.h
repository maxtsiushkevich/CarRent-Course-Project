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
    string status; // classic, silver, gold, platinum
    float count;
    string phoneNumber;
    struct Adress
    {
        string country;
        string city;
        string street;
        int house;
        int flat;
    } adress;
public:
    User();
    //User(int);
};


#endif //CARRENT_USER_H
