#ifndef CARRENT_DATABASE_H
#define CARRENT_DATABASE_H

#include "Car.h"
#include "ElectricCar.h"
#include "DieselCar.h"
#include "PetrolCar.h"
#include "HybridCar.h"
#include "OilCar.h"
#include <vector>

class Database
{
public:
    static void AddInDatabase(DieselCar&);
    static void AddInDatabase(PetrolCar&);
    static void AddInDatabase(ElectricCar&);
    static void AddInDatabase(HybridCar&);

    static void GetFromDatabase(vector<DieselCar>&);
    static void GetFromDatabase(PetrolCar&);
    static void GetFromDatabase(ElectricCar&);
    static void GetFromDatabase(HybridCar&);

    static void DeleteFromDatabase(DieselCar&);
    static void DeleteFromDatabase(PetrolCar&);
    static void DeleteFromDatabase(ElectricCar&);
    static void DeleteFromDatabase(HybridCar&);

};


#endif
