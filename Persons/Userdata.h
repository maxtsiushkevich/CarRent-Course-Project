#ifndef CARRENT_USERDATA_H
#define CARRENT_USERDATA_H

using namespace std;

class Userdata
{
    friend class Interface;
private:
    wchar_t login[30]; // ограничить длину
    wchar_t password[30];
    int id;
public:
    Userdata();
    Userdata(int);
    int GetID() { return id; }
    void SetInfo(int);
    void SetData(wchar_t*, wchar_t*);
    bool CheckAccess(int); // admin - 1, user - 2
    bool CheckLogin(wchar_t*); // admin - 1, user - 2
};


#endif //CARRENT_USERDATA_H
