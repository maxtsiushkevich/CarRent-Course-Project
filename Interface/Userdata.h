#ifndef CARRENT_USERDATA_H
#define CARRENT_USERDATA_H
#include <string>

using namespace std;

class Userdata
{
    friend class Interface;
private:
    string login;
    string password;
    int id;
public:
    Userdata();
    Userdata(int, int);
    void SetData(string, string);
    bool CheckAccess(int); // admin - 1, user - 2
    bool CheckLogin(string); // admin - 1, user - 2
};


#endif //CARRENT_USERDATA_H
