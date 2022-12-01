#ifndef CARRENT_INTERFACE_H
#define CARRENT_INTERFACE_H
#include <string>
#include "../Persons/Userdata.h"
#include "../Persons/User.h"
#include "../Persons/Admin.h"
#include "../Car/ElectricCar.h"
#include "../Car/DieselCar.h"
#include "../Car/PetrolCar.h"
#include "../Car/HybridCar.h"
#include "../Session/Session.h"
using namespace std;

class Interface
{
    friend class Session;
private:
    Userdata account;
    vector<PetrolCar> petrolCars;
    vector<DieselCar> dieselCars;
    vector<ElectricCar> electricCars;
    vector<HybridCar> hybridCar;
    vector<int> carIdInUsage;
    Session session;
    User user;
    Admin admin;
public:
    Interface();
    ~Interface() = default;
    void FirstMenu();
    void AdminAuthentication();
    void UserAuthentication();
    void UserMainMenu();
    void AdminMainMenu();
    void Registation();
    void UserAccountInfo(); // выводит информацию об аккауте пользователя
    void ShowAllSessions(); // показывает все заказы вообще
    void ShowSessions(); // показывает все заказы конкретного пользователя
};



#endif
