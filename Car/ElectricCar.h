#ifndef CARRENT_ELECTRICCAR_H
#define CARRENT_ELECTRICCAR_H
#include "Car.h"
#include <string>


class ElectricCar : virtual protected Car
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
