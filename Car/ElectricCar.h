#ifndef CARRENT_ELECTRICCAR_H
#define CARRENT_ELECTRICCAR_H
#include "Car.h"
#include <string>


class ElectricCar : private Car
{
private:
    int batteryCapacity;
public:
    //ElectricCar(int);
    //~ElectricCar();
};


#endif
