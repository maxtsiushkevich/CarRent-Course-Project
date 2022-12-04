#include "Session.h"
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

Session :: Session()
{
    userID = 0;
    carID = 0;
    cost = 0.0;
    DateFrom.day = 0;
    DateFrom.month = 0;
    DateFrom.year = 0;
    DateTo.day = 0;
    DateTo.month = 0;
    DateTo.year = 0;
}

void Session :: CreateSession(int userID, int carID, int costPerDay, int count)
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
    if (term <= 6)
    {
        cost = costPerDay * term;
    }
    if (term > 6 && term < 30)
    {
        int week = (term - (term % 7)) / 7;
        cost = week * costPerDay * 6 + (term - week * 7) * costPerDay;
    }
    if (term > 30)
    {
        int month = (term - (term % 30)) / 30;
        int week = ((term - month * 30) - ((term - month * 30) % 7)) / 7;
        cost = month * costPerDay * 26 + week * costPerDay * 6 + (term - month * 30 - week * 7) * costPerDay;
    }


    if (cost > count)
    {
        cout << "Недостаточно средств" << endl; // прерывание, если недостаточно средств
        return;
    }

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

    int a = (14 - currentTime->tm_mon+1) / 12;
    int y = currentTime->tm_year + 1900 + 4800 - a;
    int m = currentTime->tm_mon + 1 + 12 * a - 3;
    nowDays = currentTime->tm_mday + ((153*m+2)/5) + 365 * y + y/4 - y/100 + y/400 - 32045;

    if (nowDays <= daysNum)
        return true;
    else
        return false;
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
    while(file.read((char*)&session, sizeof(session)))
        sessions.emplace_back(session);
}