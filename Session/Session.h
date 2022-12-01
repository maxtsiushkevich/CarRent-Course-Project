#ifndef CARRENT_SESSION_H
#define CARRENT_SESSION_H
#include <vector>

using namespace std;

class Session
{
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
    Session(int userID, int carID, int costPerDay, int count);
    Session() { }
    ~Session() = default;
    void CreateSession();
    static void GetAllSessions(vector<Session>&);
    bool CheckDate(int);
    bool CheckDate(int, int);
    int JDDate(int, int, int);
};

#endif