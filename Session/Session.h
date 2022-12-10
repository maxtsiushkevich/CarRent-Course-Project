#ifndef CARRENT_SESSION_H
#define CARRENT_SESSION_H
#include <vector>
#include "../Persons/User.h"

using namespace std;

class Session
{
    friend class Interface;
private:
    int userID;
    int carID;
    float cost;
    struct DateFrom
    {
        int day;
        int month;
        int year;
    } DateFrom;
    struct DateTo
    {
        int day;
        int month;
        int year;
    } DateTo;
public:
    Session();
    ~Session() = default;
    bool CreateSession(int, int, int, User&); // создание заказа
    static void GetAllSessions(vector<Session>&);
    bool CheckDate(int);
    bool CheckDate(int, int);
    int JDDate(int, int, int);
};

#endif