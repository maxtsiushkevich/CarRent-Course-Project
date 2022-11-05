#ifndef CARRENT_FILEWORKER_H
#define CARRENT_FILEWORKER_H

#include "OilCar.h"
#include "DieselCar.h"
#include "PetrolCar.h"
#include "HybridCar.h"
#include "ElectricCar.h"

class FileWorker
{
public:
    FileWorker() = default;
    ~FileWorker() = default;

    void WriteInFile(OilCar);
    void WriteInFile(DieselCar);
    void WriteInFile(PetrolCar);
    void WriteInFile(ElectricCar);
    void WriteInFile(HybridCar);

    void ReadFromFile(OilCar);
    void ReadFromFile(DieselCar);
    void ReadFromFile(PetrolCar);
    void ReadFromFile(ElectricCar);
    void ReadFromFile(HybridCar);
};


#endif
