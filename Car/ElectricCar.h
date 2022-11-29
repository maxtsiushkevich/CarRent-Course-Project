#ifndef CARRENT_ELECTRICCAR_H
#define CARRENT_ELECTRICCAR_H
#include "Car.h"
#include <string>


class ElectricCar : virtual public Car
{
    friend class Database;
protected:
    int batteryCapacity;
public:
    ElectricCar();
    ElectricCar(int id) : Car(id) { };
    virtual ~ElectricCar() = default;
    int GetBatteryCapacity() { return batteryCapacity; };
};


#endif
