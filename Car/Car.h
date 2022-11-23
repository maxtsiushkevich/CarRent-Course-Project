#ifndef CARRENT_CAR_H
#define CARRENT_CAR_H
#include <string>
#include <vector>

using namespace std;

class Car
{
    friend class Database;
protected:
    int id; // ID
    bool deleteMark; // метка, удалена ли машина
    string brand, model, country, bodyType;
    int manufacturedYear; // год производства
    string transmissionType; // тип КПП
    int numberOfSeats; // количество мест
    int odometer; // пробег
    int horsepower; // лошадиные силы
    float maxSpeed; // максимальная скорость
    float to100; // разгон до 100
    struct interior
    {
        string color, material; // цвет и материал салона
    } interior;
    string color;
    int costPerDay, costPerWeek, costPerMonth; // стоимость аренды
    bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof; // опции
public:
    Car();
    Car(int odo) { odometer = odo; } ;
    virtual ~Car() = default;
    int GetId() { return id; };
    string GetBrand() { return brand; };
    string GetModel() { return model; };
    string GetCountry() { return country; };
    string GetBodyType() { return bodyType; };
    int GetNumberOfSeats() { return numberOfSeats; };
    int GetOdometer() { return odometer; };
    int GetHorsepower() { return horsepower; };
    float GetMaxSpeed() { return maxSpeed; };
    float GetTo100() { return to100; };
    string GetInteriorColor() { return interior.color; };
    string GetInteriorMaterial() { return interior.material; };
    string GetColor() { return color; };
    int GetCostPerDay() { return costPerDay; };
    int GetCostPerWeek() { return costPerWeek; };
    int GetCostPerMonth() { return costPerMonth; };
};
#endif
