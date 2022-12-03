#ifndef CARRENT_HYBRIDCAR_H
#define CARRENT_HYBRIDCAR_H
#include "Car.h"
#include "ElectricCar.h"
#include "OilCar.h"
#include <string>

class HybridCar : public ElectricCar, public OilCar
{
    friend class Database;
protected:
    wchar_t fuelType[6];
public:
    HybridCar() : Car(), OilCar(), ElectricCar() { }
    HybridCar(int id) : OilCar(id), ElectricCar(id) { };
    ~HybridCar() = default;
    void SetInfo();
    wstring GetFuelType() { return fuelType; };

};

#endif