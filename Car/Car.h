#ifndef CARRENT_CAR_H
#define CARRENT_CAR_H
#include <string>

using namespace std;

class Car
{
protected:
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
        float maxSpeed;
        float to100;
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
    virtual ~Car();
    virtual string getPlate();
    virtual int getOdometer();
    virtual string getBodyType();
    virtual string getBrand();
    virtual string getModel();
    virtual string getCountry();
    virtual string getTransmission();

    //virtual void writeInFile();
    //virtual void readFromFile();

    //virtual void printAllCars();
    //virtual void printByCriteria(string);
    //virtual void printByCriteria(int);
    //virtual void printByCriteria(float);
    virtual void printAllInfo();
};
#endif
