#ifndef CARRENT_ELECTRICCAR_H
#define CARRENT_ELECTRICCAR_H
#include "Car.h"
#include <string>


class ElectricCar : virtual public Car
{
protected:
    int batteryCapacity;
public:
    ElectricCar();
    ElectricCar(int);
    virtual ~ElectricCar();
    // геттеры


};


#endif
