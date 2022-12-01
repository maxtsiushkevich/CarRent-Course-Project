#ifndef CARRENT_USERDATA_H
#define CARRENT_USERDATA_H

using namespace std;

class Userdata
{
    friend class Interface;
private:
    char login[60]; // ограничить длину
    char password[60];
    int id;
public:
    Userdata();
    Userdata(int);
    int GetID() { return id; }
    void SetInfo(int);
    void SetData(char*, char*);
    bool CheckAccess(int); // admin - 1, user - 2
    bool CheckLogin(char*); // admin - 1, user - 2
};


#endif //CARRENT_USERDATA_H
