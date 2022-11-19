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
    string fuelType;
    int batteryCapacity;
    float consumption;
    float engineVolume;
public:
    HybridCar();
    HybridCar(int);
    ~HybridCar();

};

#endif