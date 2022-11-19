#ifndef CARRENT_INTERFACE_H
#define CARRENT_INTERFACE_H
#include <string>
#include "Userdata.h"

using namespace std;

class Interface
{
private:
    Userdata account;
public:
    Interface();
    ~Interface() = default;
    void FirstMenu();
    void AdminAuthentication();
    void UserAuthentication();
    void UserMainMenu();
    void AdminMainMenu();
    void Registation();
};



#endif
