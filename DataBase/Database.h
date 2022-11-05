#ifndef CARRENT_DATABASE_H
#define CARRENT_DATABASE_H

#include "Car.h"
#include "ElectricCar.h"
#include "DieselCar.h"
#include "PetrolCar.h"
#include "HybridCar.h"
#include "OilCar.h"

class Database
{
public:
    Database() = default;
    ~Database() = default;

    static void AddInDatabase(OilCar&);
    static void AddInDatabase(DieselCar&);
    static void AddInDatabase(PetrolCar&);
    static void AddInDatabase(ElectricCar&);
    static void AddInDatabase(HybridCar&);

    static void GetFromDatabase(OilCar&);
    static void GetFromDatabase(DieselCar&);
    static void GetFromDatabase(PetrolCar&);
    static void GetFromDatabase(ElectricCar&);
    static void GetFromDatabase(HybridCar&);
};


#endif
