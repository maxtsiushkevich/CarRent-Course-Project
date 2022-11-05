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
    OilCar(int);
    virtual ~OilCar();
    float GetVolume();
    float GetConsuption();
};

#endif
