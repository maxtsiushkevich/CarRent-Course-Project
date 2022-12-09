#ifndef CARRENT_INTERFACE_H
#define CARRENT_INTERFACE_H
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
protected:
    vector<PetrolCar> petrolCars; // все авто
    vector<DieselCar> dieselCars;
    vector<ElectricCar> electricCars;
    vector<HybridCar> hybridCars;

    vector<int> carIdInUsage; // id машин, которые недоступны

    Session newSession;
    vector<Session> allSessions;

    User user;
    Admin admin;
public:
    Interface();
    ~Interface() = default;
    void FirstMenu(); // главное меню, открывается при запуске
    void UserMainMenu(); // главное меню пользователя
    void AdminMainMenu(); // главное меню администратора
    void Registation(); // регистрация
    void UserAccountInfo(); // выводит информацию об аккауте пользователя
    void ChoosingCar(); // показывает все заказы вообще

    bool ShowCars(int); // выводит автомобили
    void AddCount(); // пополнение баланса
    int FindCost(int, int); // ищет стоимость аренды по его ID
    void RefreshUserInFile();




    void ShowAllSessions(); // показывает все заказы вообще
    void ShowSessions(); // показывает все заказы конкретного пользователя
    void UserAccountSettings(); // изменение данных аккаунта администратора
};

// добавление машины: вызов конструктора (там же записывается в файл) -> добавляется в соответствующий вектор



#endif
