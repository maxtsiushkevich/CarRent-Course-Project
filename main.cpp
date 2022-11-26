#include <iostream>
#include <string>
#include <fstream>
#include "Persons/User.h"
#include "Persons/Admin.h"
#include "Car/Car.h"
#include "Car/ElectricCar.h"
#include "Car/DieselCar.h"
#include "Car/PetrolCar.h"
#include "Car/HybridCar.h"
#include "Car/OilCar.h"
#include "Interface/Interface.h"
#include "Database/Database.h"
using namespace std;

int main()
{
    //Interface menu;

    //DieselCar c1;
    //Database::AddInDatabase(c1);

      //Car c1(0);


     // char string[30];
//      fgets(string, 30, stdin);
//      ofstream file;
//      file.open("tmp.bin", ios::binary | ios::app);
//      file.write((char*)&string, sizeof(string));
//      file.close();

//    ifstream file;
//    file.open("tmp.bin", ios::binary);
//    file.read((char*)&string, sizeof(string));
//    cout << string << endl;
//    file.close();


//    vector<DieselCar> dieselCars;
//    Database::GetFromDatabase(dieselCars);
//
//    for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
//    {
//        cout << it->GetBrand() << ' ' << it->GetModel() << endl;
//    }
//
//    cout << '\n';
//
//    Database::DeleteFromDatabase(dieselCars[0]);
//
//   for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
//   {
//       cout << it->GetBrand() << ' ' << it->GetModel() << endl;
//   }

    return 0;
}