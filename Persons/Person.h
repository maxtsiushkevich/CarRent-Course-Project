#ifndef CARRENT_PERSON_H
#define CARRENT_PERSON_H
#include "Session.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class Person
{
private:
    string name;
    int age;
    //map<string, vector<Session>>;
public:
    Person();
    ~Person();
};


#endif
