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
    wchar_t brand[30], model[30], country[30], bodyType[30];
    int manufacturedYear; // год производства
    wchar_t transmissionType[4];
    int numberOfSeats; // количество мест
    int horsepower; // лошадиные силы
    float maxSpeed; // максимальная скорость
    float to100; // разгон до 100
    struct interior
    {
        wchar_t color[30], material[30];
    } interior;
    wchar_t color[30];
    int costPerDay; // стоимость аренды
    bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof; // опции
public:
    Car();
    Car(int id) { this->id = id; } ;
    virtual ~Car() = default;
    virtual void SetInfo();
    int GetId() { return id; };
    wstring GetBrand() { return brand; };
    wstring GetModel() { return model; };
    wstring GetCountry() { return country; };
    wstring GetBodyType() { return bodyType; };
    wstring GetTransmissionType() { return transmissionType; };
    int GetNumberOfSeats() { return numberOfSeats; };
    int GetHorsepower() { return horsepower; };
    float GetMaxSpeed() { return maxSpeed; };
    float GetTo100() { return to100; };
    wstring GetInteriorColor() { return interior.color; };
    wstring GetInteriorMaterial() { return interior.material; };
    wstring GetColor() { return color; };
    int GetCostPerDay() { return costPerDay; };
};
#endif
