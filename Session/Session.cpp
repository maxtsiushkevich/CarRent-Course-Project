#include "Session.h"
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

Session :: Session(int userID, int carID, int costPerDay, int count)
{
    int term;
    int JDNDay[2];

    cout << "С какой даты начинается аренда? Введите день, месяц и год через пробел" << endl;
    cin >> DateFrom.day; // добавить проверки
    cin >> DateFrom.month;
    cin >> DateFrom.year;
    JDNDay[0] = JDDate(DateFrom.day, DateFrom.month, DateFrom.year);
    while (!this->CheckDate(JDNDay[0]))
    {
        cout << "Ошибка! Введите дату еще раз!" << endl;
        cin >> DateFrom.day; // добавить проверки
        cin >> DateFrom.month;
        cin >> DateFrom.year;
    }

    cout << "До какой даты аренда? Введите день, месяц и год через пробел\"" << endl;
    cin >> DateTo.day; // добавить проверки
    cin >> DateTo.month;
    cin >> DateTo.year;
    JDNDay[1] = JDDate(DateTo.day, DateTo.month, DateTo.year);
    while (!this->CheckDate(JDNDay[0], JDNDay[1]))
    {
        cout << "Ошибка! Введите дату еще раз!" << endl;
        cin >> DateTo.day; // добавить проверки
        cin >> DateTo.month;
        cin >> DateTo.year;
    }
    term = JDNDay[1] - JDNDay[0];

    // механизм расчета стоимости поездки

    //if (cost > user.count)
    //    cout << "Недостаточно средств" << endl;

    ofstream file;
    file.open("../Files/Session.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)this, sizeof(this));
    file.close();

}

bool Session :: CheckDate(int daysNum)
{
    int nowDays;
    time_t seconds = time(NULL);
    tm* currentTime = localtime(&seconds);

    int a = (14 - currentTime->tm_mon) / 12;
    int y = currentTime->tm_year + 1900 + 4800 - a;
    int m = currentTime->tm_mon + 12 * a - 3;
    nowDays = currentTime->tm_mday + ((153*m+2)/5) + 365 * y + y/4 - y/100 + y/400 - 32045;

    if (nowDays > daysNum)
        return false;
    else
        return true;
}

bool Session :: CheckDate(int daysNumFrom, int daysNumTo)
{
    if (daysNumFrom > daysNumTo)
        return false;
    else
        return true;
}


int Session :: JDDate(int day, int month, int year)
{
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    int result = day + ((153*m+2)/5) + 365 * y + y/4 - y/100 + y/400 - 32045;
    return result;
}

void Session :: GetAllSessions(vector<Session>&sessions)
{
    Session session;
    ifstream file;
    file.open("../Files/Session.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while(file.read((char*)&obj, sizeof(obj)))
        sessions.emplace_back(obj);
}