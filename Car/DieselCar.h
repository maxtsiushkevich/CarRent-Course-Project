#ifndef CARRENT_DIESELCAR_H
#define CARRENT_DIESELCAR_H
#include "OilCar.h"

class DieselCar : public OilCar
{
    friend class Database;
public:
    DieselCar() { };
    ~DieselCar() = default;
    void SetInfo() { OilCar::SetInfo(); };
};


#endif
