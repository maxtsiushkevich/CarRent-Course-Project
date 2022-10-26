#ifndef CARRENT_PETROLCAR_H
#define CARRENT_PETROLCAR_H
#include "OilCar.h"

class PetrolCar : virtual public OilCar
{
protected:
    int petrolType;
private:
    PetrolCar();
    PetrolCar (int);
    ~PetrolCar();
};


#endif
