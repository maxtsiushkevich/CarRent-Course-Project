#ifndef CARRENT_CAR_H
#define CARRENT_CAR_H
#include <string>

using namespace std;

class Car // виртуальный деструктор
{
    friend class Admin;
private:
    string brand; // бренд
    string model; // модель
    string carPlate; // госномер
    int costPerDay; // стоимость в день
    int costPerWeek; // в неделю
    int costPerMonth; // в месяц
    int odometer; // пробег
    int manufacturedYear; // год
    string bodyType; // тип кузова

    string country; // страна
    string transmissionType; // КПП

    struct engine // двигатель
    {
        int horsepower;
        double maxSpeed;
        double to100;
    } engine;

    struct interior // интерьер
    {
        string color;
        string material;
    } interior;

    struct exterior // экстерьер
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
    //Car(string);
    Car();
    //virtual ~Car();
    double getTariff();
    string getPlate();
    double getOdometer();
    string getBodyType();
    string getBrand();
    string getModel();
    string getCountry();
    string getTransmission();
};
#endif
