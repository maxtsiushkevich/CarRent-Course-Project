#ifndef CARRENT_CAR_H
#define CARRENT_CAR_H
#include <string>

using namespace std;

class Car
{
    friend class CarBrands;
    friend class Database;
protected:
    int id;
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
    //static int count;

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
    string GetPlate();

    //bool IsDelete();





    //virtual void printAllCars();
    //virtual void printByCriteria(string);
    //virtual void printByCriteria(int);
    //virtual void printByCriteria(float);
    //virtual void printAllInfo();
};
#endif
