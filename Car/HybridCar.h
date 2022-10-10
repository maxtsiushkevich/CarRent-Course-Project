#ifndef CARRENT_HYBRIDCAR_H
#define CARRENT_HYBRIDCAR_H
#include "Car.h"
#include <string>

class HybridCar : private Car
{
    int batteryCapacity;
    double consumption;
    double engineVolume;
};

#endif