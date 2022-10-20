#ifndef CARRENT_HYBRIDCAR_H
#define CARRENT_HYBRIDCAR_H
#include "Car.h"
#include "ElectricCar.h"
#include "OilCar.h"
#include <string>

class HybridCar : private ElectricCar, private OilCar
{
private:
    //int batteryCapacity;
    //float consumption;
    //float engineVolume;
public:
   /* HybridCar();
    ~HybridCar();*/
};

#endif