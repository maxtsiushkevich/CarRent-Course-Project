#ifndef CARRENT_DIESELCAR_H
#define CARRENT_DIESELCAR_H
#include "OilCar.h"

class DieselCar : virtual public OilCar
{
private:
    DieselCar();
    DieselCar (int);
    ~DieselCar();

};


#endif
