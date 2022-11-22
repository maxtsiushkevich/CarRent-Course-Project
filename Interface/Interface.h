#ifndef CARRENT_INTERFACE_H
#define CARRENT_INTERFACE_H
#include <string>
#include "../Persons/Userdata.h"
#include "../Car/ElectricCar.h"
#include "../Car/DieselCar.h"
#include "../Car/PetrolCar.h"
#include "../Car/HybridCar.h"
using namespace std;

class Interface
{
private:
    Userdata account;
    vector<PetrolCar> petrolCars;
    vector<DieselCar> dieselCars;
    vector<ElectricCar> electricCars;
    vector<HybridCar> hybridCar;
public:
    Interface();
    ~Interface() = default;
    void FirstMenu();
    void AdminAuthentication();
    void UserAuthentication();
    void UserMainMenu();
    void AdminMainMenu();
    void Registation();
};



#endif
