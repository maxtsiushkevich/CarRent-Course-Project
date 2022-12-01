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
    char name[60];
    char surname[60];
    int age;
public:
    Person();
    ~Person() = default;
    int GetID() { return id; }
    virtual void SetInfo();
    //char* GetName() { return name; }
};


#endif