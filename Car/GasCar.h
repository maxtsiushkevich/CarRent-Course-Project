#ifndef CARRENT_GASCAR_H
#define CARRENT_GASCAR_H
#include "Car.h"
#include <string>

class GasCar : private Car
{
    int gasCapacity;
    double gasConsumption; // 110-120% от бензина
};

#endif