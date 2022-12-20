#ifndef CARRENT_OILCAR_H
#define CARRENT_OILCAR_H

#include "Car.h"
#include <string>

class OilCar : virtual public Car {
    friend class Database;

protected:
    float consumption; // расход
    float volume; // объем
public:
    OilCar();

    virtual ~OilCar() = default;

    void SetInfo();

    float GetConsumption() { return consumption; };

    float GetVolume() { return volume; };
};

#endif
