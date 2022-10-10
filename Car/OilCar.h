#ifndef CARRENT_OILCAR_H
#define CARRENT_OILCAR_H
#include "Car.h"
#include <string>

class OilCar : private Car
{
private:
    double consumption; // расход
    double engineVolume; // объем

};

#endif
