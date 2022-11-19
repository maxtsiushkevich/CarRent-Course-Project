#ifndef CARRENT_PERSON_H
#define CARRENT_PERSON_H
#include <string>
#include <vector>
#include <map>

using namespace std;

class Person
{
protected:
    int id;
    string name;
    string surname;
    int age;
public:
    Person();
    Person(int);
    ~Person();
};


#endif
