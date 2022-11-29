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
    char brand[60], model[60], country[60], bodyType[60];
    int manufacturedYear; // год производства
    char transmissionType[8];
    int numberOfSeats; // количество мест
    int horsepower; // лошадиные силы
    float maxSpeed; // максимальная скорость
    float to100; // разгон до 100
    struct interior
    {
        char color[60], material[60];
    } interior;
    char color[60];
    int costPerDay; // стоимость аренды
    bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof; // опции
public:
    Car();
    Car(int id) { this->id = id; } ;
    virtual ~Car() = default;
    int GetId() { return id; };
    string GetBrand() { return brand; };
    string GetModel() { return model; };
    string GetCountry() { return country; };
    string GetBodyType() { return bodyType; };
    string GetTransmissionType() { return transmissionType; };
    int GetNumberOfSeats() { return numberOfSeats; };
    int GetHorsepower() { return horsepower; };
    float GetMaxSpeed() { return maxSpeed; };
    float GetTo100() { return to100; };
    string GetInteriorColor() { return interior.color; };
    string GetInteriorMaterial() { return interior.material; };
    string GetColor() { return color; };
    int GetCostPerDay() { return costPerDay; };
};
#endif
