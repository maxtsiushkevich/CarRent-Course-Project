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
    HybridCar();
    HybridCar(int odo) : OilCar(odo), ElectricCar(odo) { };
    ~HybridCar() = default;
    string GetFuelType() { return fuelType; };

};

#endif