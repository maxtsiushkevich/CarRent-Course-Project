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
    PetrolCar(int id) :Car(id), OilCar(id) { };
    virtual ~PetrolCar() = default;
    void SetInfo();
    int GetPetrolType() { return petrolType; };
};


#endif
