#ifndef CARRENT_PERSON_H
#define CARRENT_PERSON_H
#include <string>

using namespace std;

class Person
{
private:
    int id;
    string name;
    int age;

public:
    Person();
    void getName();
};


#endif
