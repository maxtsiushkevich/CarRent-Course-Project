#ifndef CARRENT_PETROLCAR_H
#define CARRENT_PETROLCAR_H
#include "OilCar.h"

class PetrolCar : public OilCar
{
protected:
    int petrolType;
public:
    PetrolCar();
    PetrolCar (int);
    ~PetrolCar();
    int GetPetrolType();
};


#endif
