#ifndef CARRENT_PERSON_H
#define CARRENT_PERSON_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Person {
protected:
    int id;
    wchar_t name[30] = {L"\0"};
    wchar_t surname[30] = {L"\0"};
    int age;
public:
    Person();

    ~Person() = default;

    int GetID() { return id; }

    wchar_t *GetName() { return name; }

    wchar_t *GetSurname() { return surname; };

    int GetAge() { return age; }

    virtual void SetInfo();
};


#endif