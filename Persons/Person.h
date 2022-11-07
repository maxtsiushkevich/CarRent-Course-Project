#ifndef CARRENT_PERSON_H
#define CARRENT_PERSON_H
#include <string>
#include <vector>
#include <map>

using namespace std;

class Person
{
private:
    int id;
    string name;
    int age;
public:
    Person();
    Person(int);
    ~Person();
};


#endif
