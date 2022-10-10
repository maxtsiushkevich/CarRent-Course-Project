#ifndef CARRENT_ELECTRICCAR_H
#define CARRENT_ELECTRICCAR_H
#include "Car.h"
#include <string>


class ElecticCar : private Car
{
private:
    int batteryCapacity;
};


#endif
