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
    char fuelType[60];
public:
    HybridCar() : Car(), OilCar(), ElectricCar() { }
    HybridCar(int id) : OilCar(id), ElectricCar(id) { };
    ~HybridCar() = default;
    void SetInfo();
    string GetFuelType() { return fuelType; };

};

#endif