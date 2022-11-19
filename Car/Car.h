#ifndef CARRENT_CAR_H
#define CARRENT_CAR_H
#include <string>
#include <vector>

using namespace std;

class Car
{
    friend class Database;
protected:
    int id;
    bool deleteMark;
    string brand, model, country, bodyType;
    int manufacturedYear;
    string transmissionType;
    int numberOfSeats;
    int odometer;
    struct engine
    {
        int horsepower;
        float maxSpeed;
        float to100;
    } engine;
    struct interior
    {
        string color, material;
    } interior;
    string color;
    int costPerDay, costPerWeek, costPerMonth;
    bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;

public:
    Car(int);
    Car();
    virtual ~Car();
    string GetBrand();
    string GetModel();
    int GetManufacturedYear();
    string GetCountry();
    string GetBodyType();
    int GetNumberOfSeats();
    string GetTransmissionType();
    int GetOdometer();
    int GetId();
};
#endif
