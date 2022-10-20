#ifndef CARRENT_ELECTRICCAR_H
#define CARRENT_ELECTRICCAR_H
#include "Car.h"
#include <string>


class ElectricCar : private Car
{
protected:
    int batteryCapacity;
public:
    ElectricCar();
    virtual ~ElectricCar();
    void writeInFile();
    void readFromFile();

};


#endif
