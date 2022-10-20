#ifndef CARRENT_OILCAR_H
#define CARRENT_OILCAR_H
#include "Car.h"
#include <string>

class OilCar : private Car
{
protected:
    struct engine
    {
        float consumption; // расход
        float engineVolume; // объем
    } engine;
public:
    OilCar();
    OilCar(int);
    virtual ~OilCar();
    void writeInFile();
    void readFromFile();
    void printAll();
};

#endif
