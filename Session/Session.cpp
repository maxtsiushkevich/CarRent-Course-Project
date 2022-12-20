#include "Session.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include "../Persons/User.h"
#include "../Interface/CarInUsage.h"

using namespace std;

Session::Session() {
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

bool Session::CreateSession(int userID, int carID, int costPerDay, User &user) {
    if (costPerDay == 0) {
        cout << "Введен неверный номер автомобиля" << endl;
        return false;
    }
    this->userID = userID;
    this->carID = carID;
    int term;
    int JDNDay[2];
    cout << "С какой даты начинается аренда? Введите день, месяц и год через пробел" << endl;
    cin >> DateFrom.day; // добавить проверки
    cin >> DateFrom.month;
    cin >> DateFrom.year;
    JDNDay[0] = JDDate(DateFrom.day, DateFrom.month, DateFrom.year);
    while (!this->CheckDate(JDNDay[0]) && !this->InputDateCheck(DateFrom.day, DateFrom.month, DateFrom.year)) {
        cout << "Ошибка! Введите дату еще раз!" << endl;
        cin >> DateFrom.day;
        cin >> DateFrom.month;
        cin >> DateFrom.year;
        JDNDay[0] = JDDate(DateFrom.day, DateFrom.month, DateFrom.year);
    }
    if (JDNDay[0] - NowDays() > 3) {
        cout << "Ошибка! Максимальный срок до начала аренды - 3 дня" << endl;
        return false;
    }
    cout << "До какой даты аренда? Введите день, месяц и год через пробел" << endl;
    cin >> DateTo.day;
    cin >> DateTo.month;
    cin >> DateTo.year;
    JDNDay[1] = JDDate(DateTo.day, DateTo.month, DateTo.year);
    while (!this->CheckDate(JDNDay[0], JDNDay[1]) &&
           !this->InputDateCheck(DateFrom.day, DateFrom.month, DateFrom.year)) {
        cout << "Ошибка! Введите дату еще раз!" << endl;
        cin >> DateTo.day;
        cin >> DateTo.month;
        cin >> DateTo.year;
        JDNDay[1] = JDDate(DateFrom.day, DateFrom.month, DateFrom.year);
    }
    term = JDNDay[1] - JDNDay[0] + 1;
    // механизм расчета стоимости поездки
    if (term == 0)
        cost = costPerDay;
    if (term > 0 || term <= 6) {
        cost = costPerDay * term;
    }
    if (term > 6 && term < 30) {
        int week = (term - (term % 7)) / 7;
        cost = week * costPerDay * 6 + (term - week * 7) * costPerDay;
    }
    if (term > 30) {
        int month = (term - (term % 30)) / 30;
        int week = ((term - month * 30) - ((term - month * 30) % 7)) / 7;
        cost = month * costPerDay * 26 + week * costPerDay * 6 + (term - month * 30 - week * 7) * costPerDay;
    }
    if (cost > user.GetCount()) {
        cout << "Недостаточно средств" << endl; // прерывание, если недостаточно средств
        return false;
    }
    if (!wcscmp(user.GetStatus(), L"Silver"))
        cost = cost - (cost * 0.05);
    if (!wcscmp(user.GetStatus(), L"Gold"))
        cost = cost - (cost * 0.1);
    if (!wcscmp(user.GetStatus(), L"Platinum"))
        cost = cost - (cost * 0.15);
    cout << "Стоимость аренды составит " << cost << "BYN " << endl;
    cout << "Для подтверждения заказа введите '1'\n"
            "Для отмены заказа введите '2'" << endl;
    int tmp;
    cin >> tmp;
    while (tmp > 2 || tmp < 1) {
        cout << "Ошибка. Введите еще раз:" << endl;
        cin >> tmp;
    }
    if (tmp == 2)
        return false;
    user.SetCount(-1 * cost);
    user.SetSpendMoney(cost);
    CarInUsage object(JDNDay[1], carID);
    object.WriteInFile();
    ofstream file;
    file.open("/Users/max/Desktop/CarRent/Files/Session.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char *) this, sizeof(Session));
    file.close();
    cout << "Заказ успешно оформлен!" << endl;
    return true;
}

int Session::NowDays() {
    int nowDays;
    time_t seconds = time(NULL);
    tm *currentTime = localtime(&seconds);
    int a = (14 - currentTime->tm_mon + 1) / 12;
    int y = currentTime->tm_year + 1900 + 4800 - a;
    int m = currentTime->tm_mon + 1 + 12 * a - 3;
    nowDays = currentTime->tm_mday + ((153 * m + 2) / 5) + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    return nowDays;
}

bool Session::CheckDate(int daysNum) {
    int nowDays = NowDays();
    if (nowDays <= daysNum)
        return true;
    else
        return false;
}

bool Session::CheckDate(int daysNumFrom, int daysNumTo) {
    if (daysNumFrom > daysNumTo)
        return false;
    else
        return true;
}

int Session::JDDate(int day, int month, int year) {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    int result = day + ((153 * m + 2) / 5) + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    return result;
}

void Session::GetAllSessions(vector<Session> &allSessions) {
    Session session;
    ifstream file;
    file.open("../Files/Session.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while (file.read((char *) &session, sizeof(Session)))
        allSessions.push_back(session);
}

bool Session::InputDateCheck(int day, int month, int year) {
    while (year > 2022)
        return false;
    while (month > 12)
        return false;
    while (month == 1 || month == 3 || month == 5 || month == 7 ||
           month == 8 || month == 10 || month == 12 && day > 31)
        return false;
    while (month == 4 || month == 6 ||
           month == 9 || month == 11 && day > 30)
        return false;
    while (month == 2 && year % 4 == 0 && day > 29)
        return false;
    while (month == 2 && year % 4 != 0 && day > 28)
        return false;
    return true;
}