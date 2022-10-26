#ifndef CARRENT_CAR_H
#define CARRENT_CAR_H
#include <string>

using namespace std;

class Car
{
protected:
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

    virtual string getBrand();
    virtual string getModel();
    virtual string getCountry();
    virtual string getBodyType();
    virtual int getManufacturedYear();
    virtual int getNumberOfSeats();
    virtual string getTransmissionType();
    virtual int getOdometer();
    virtual string getPlate();





    //virtual void writeInFile();
    //virtual void readFromFile();

    //virtual void printAllCars();
    //virtual void printByCriteria(string);
    //virtual void printByCriteria(int);
    //virtual void printByCriteria(float);
    //virtual void printAllInfo();
};
#endif
