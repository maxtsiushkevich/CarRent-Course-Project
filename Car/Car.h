#ifndef CARRENT_CAR_H
#define CARRENT_CAR_H
#include <string>

using namespace std;

class Car
{
protected:
    bool deleteMark;
    string brand;
    string model;
    string country;
    string bodyType;
    int manufacturedYear;
    string transmissionType;
    int numberOfSeats;
    int odometer;
    string plate;
    struct engine
    {
        int horsepower;
        float maxSpeed;
        float to100;
    } engine;

    struct interior
    {
        string color;
        string material;
    } interior;

    string color;

    int costPerDay;
    int costPerWeek;
    int costPerMonth;

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
    virtual ~Car();

//    virtual string GetBrand();
//    virtual int GetManufacturedYear();
//    virtual string GetModel();
//    virtual string GetCountry();
//    virtual string GetBodyType();
//    virtual int GetManufacturedYear();
//    virtual int GetNumberOfSeats();
//    virtual string GetTransmissionType();
//    virtual int GetOdometer();
//    virtual string GetPlate();





    //virtual void printAllCars();
    //virtual void printByCriteria(string);
    //virtual void printByCriteria(int);
    //virtual void printByCriteria(float);
    //virtual void printAllInfo();
};
#endif
