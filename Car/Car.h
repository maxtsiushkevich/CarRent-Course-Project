#ifndef CARRENT_CAR_H
#define CARRENT_CAR_H
#include <string>

using namespace std;

class Car
{
    friend class Admin;
private:
    string brand;
    string model;
    string carPlate;
    int costPerDay;
    int costPerWeek;
    int costPerMonth;
    int odometer;
    int manufacturedYear;
    string bodyType;

    string country;
    string transmissionType;

    struct engine
    {
        int horsepower;
        double maxSpeed;
        double to100;
    } engine;

    struct interior
    {
        string color;
        string material;
    } interior;

    struct exterior
    {
        string color;
    } exterior;

    bool cruiseControl;
    bool parkingAssist;
    bool music;
    bool bluetooth;
    bool climat;
    bool seatHeating;
    bool gps;
    bool sunroof;
public:
    Car(int);
    Car();
    //virtual ~Car();
    string getPlate();
    double getOdometer();
    string getBodyType();
    string getBrand();
    string getModel();
    string getCountry();
    string getTransmission();

};
#endif
