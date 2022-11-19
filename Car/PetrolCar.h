#ifndef CARRENT_PETROLCAR_H
#define CARRENT_PETROLCAR_H
#include "OilCar.h"

class PetrolCar : public OilCar
{
    friend class Database;
protected:
    int petrolType;
public:
    PetrolCar();
    PetrolCar(int odo) : OilCar(odo) { };
    virtual ~PetrolCar() = default;
    int GetPetrolType() { return petrolType; };
};


#endif
