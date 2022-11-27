#ifndef CARRENT_ADMIN_H
#define CARRENT_ADMIN_H
#include "Person.h"
#include <string>
#include <vector>

using namespace std;

class Admin : public Person
{
public:
    Admin();
    //Admin(int) { };
    ~Admin() = default;
};


#endif //CARRENT_ADMIN_H
