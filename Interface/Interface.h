#ifndef CARRENT_INTERFACE_H
#define CARRENT_INTERFACE_H
#include <string>
using namespace std;

class Interface
{
protected:
    int mode; // mode 1 - admin, mode 2 - user
    struct userdata
    {
        string login;
        string password;
    } userdata;
public:
    void authentication();
    void registration();
};



#endif
