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
    virtual ~ElectricCar() = default;
    void SetInfo();
    int GetBatteryCapacity() { return batteryCapacity; };
};


#endif
