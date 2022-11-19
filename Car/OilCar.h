#ifndef CARRENT_OILCAR_H
#define CARRENT_OILCAR_H
#include "Car.h"
#include <string>

class OilCar : virtual public Car
{
    friend class Database;
protected:
    float consumption; // расход
    float volume; // объем
public:
    OilCar();
    OilCar(int odo) : Car(odo) { };
    virtual ~OilCar() = default;
    float GetConsumption() { return consumption; };
    float GetVolume() { return volume; };
};

#endif
