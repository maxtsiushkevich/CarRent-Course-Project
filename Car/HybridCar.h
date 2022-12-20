#ifndef CARRENT_HYBRIDCAR_H
#define CARRENT_HYBRIDCAR_H

#include "Car.h"
#include "ElectricCar.h"
#include "OilCar.h"
#include <string>

class HybridCar : public ElectricCar, public OilCar {
    friend class Database;

protected:
    wchar_t fuelType[8] = {L"\0"};
public:
    HybridCar() : Car(), OilCar(), ElectricCar() {}

    ~HybridCar() = default;

    void SetInfo();

    wchar_t *GetFuelType() { return fuelType; };
};

#endif