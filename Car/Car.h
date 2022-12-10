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
    wchar_t transmissionType[5];
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
public:
    Car();
    Car(int id) { this->id = id; } ;
    virtual ~Car() = default;
    virtual void SetInfo();
    int GetID() { return id; };
    int GetManufacturedYear() { return manufacturedYear; };
    wchar_t* GetBrand() { return brand; };
    wchar_t* GetModel() { return model; };
    wchar_t* GetCountry() { return country; };
    wchar_t* GetBodyType() { return bodyType; };
    wchar_t* GetTransmissionType() { return transmissionType; };
    int GetNumberOfSeats() { return numberOfSeats; };
    int GetHorsepower() { return horsepower; };
    float GetMaxSpeed() { return maxSpeed; };
    float GetTo100() { return to100; };
    wchar_t* GetInteriorColor() { return interior.color; };
    wchar_t* GetInteriorMaterial() { return interior.material; };
    wchar_t* GetColor() { return color; };
    int GetCostPerDay() { return costPerDay; };
};
#endif
