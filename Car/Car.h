#ifndef CARRENT_CAR_H
#define CARRENT_CAR_H

#include <string>
#include <vector>1


using namespace std;

class Car {
    friend class Database;

protected:
    int id; // ID
    bool deleteMark; // метка, удалена ли машина
    wchar_t brand[30] = {L"\0"}, model[30] = {L"\0"}, country[30] = {L"\0"}, bodyType[30] = {L"\0"};
    int manufacturedYear; // год производства
    int numberOfSeats; // количество мест
    float maxSpeed; // максимальная скорость
    struct interior {
        wchar_t color[30] = {L"\0"}, material[30] = {L"\0"};
    } interior;
    wchar_t color[30] = {L"\0"};
    int costPerDay; // стоимость аренды
public:
    Car();

    virtual ~Car() = default;

    virtual void SetInfo();

    bool IsDelete() { return deleteMark; } // при удалении цена аренды 0
    void DeleteCar() {
        deleteMark = true;
        costPerDay = 0;
    }

    int GetID() { return id; };

    int GetManufacturedYear() { return manufacturedYear; };

    wchar_t *GetBrand() { return brand; };

    wchar_t *GetModel() { return model; };

    wchar_t *GetCountry() { return country; };

    wchar_t *GetBodyType() { return bodyType; };

    int GetNumberOfSeats() { return numberOfSeats; };

    float GetMaxSpeed() { return maxSpeed; };

    wchar_t *GetInteriorColor() { return interior.color; };

    wchar_t *GetInteriorMaterial() { return interior.material; };

    wchar_t *GetColor() { return color; };

    int GetCostPerDay() { return costPerDay; };
};

#endif
