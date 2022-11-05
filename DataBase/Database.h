#ifndef CARRENT_DATABASE_H
#define CARRENT_DATABASE_H


class Database
{
public:
    void AddInDatabase(OilCar);
    void AddInDatabase(DieselCar);
    void AddInDatabase(PetrolCar);
    void AddInDatabase(ElectricCar);
    void AddInDatabase(HybridCar);

    void GetFromDatabase(OilCar);
    void GetFromDatabase(DieselCar);
    void GetFromDatabase(PetrolCar);
    void GetFromDatabase(ElectricCar);
    void GetFromDatabase(HybridCar);
};


#endif
