#ifndef CARRENT_SESSION_H
#define CARRENT_SESSION_H


class Session
{
    int userID;
    int carID;
    int cost;
    int distance;
    struct DateFrom
    {
        int day;
        int month;
        int year;
    };
    struct DateTo
    {
        int day;
        int month;
        int year;
    };

};

#endif //CARRENT_SESSION_H
