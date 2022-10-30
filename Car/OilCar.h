#ifndef CARRENT_OILCAR_H
#define CARRENT_OILCAR_H
#include "Car.h"
#include <string>

class OilCar : virtual public Car
{
protected:
    struct engine
    {
        float consumption; // расход
        float volume; // объем
    } engine;
public:
    OilCar();
    OilCar(int);
    virtual ~OilCar();
    int getYear();
};

#endif
