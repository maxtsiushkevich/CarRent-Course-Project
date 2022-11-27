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
    //Admin admin;
    //Interface menu;
    //DieselCar c1(0);
    //Database::AddInDatabase(c1);

    vector<DieselCar> dieselCars;
    Database::GetFromDatabase(dieselCars);


    Database::DeleteFromDatabase(dieselCars[1]);
    Database::GetFromDatabase(dieselCars);
    for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
    {
        cout << it->GetBrand() << ' ';
        cout << it->GetModel() << endl;
    }


    //cout << dieselCars[0].GetBodyType() << endl;
      //setlocale(LC_ALL, "Russian");

      //string str;
      //str.reserve(30);
      //cin >> str;
      //cout << "Length: " << str.length() << endl;
      //cout << "Capacity: " << str.capacity() << endl;
      //string str1;
      //str1.reserve(30);
      //str1 = str;
      //cout << "Length: " << str1.length() << endl;
      //cout << "Capacity: " << str1.capacity() << endl;


      //ofstream file;
      //file.open("tmp.bin", ios::binary | ios::app);
      //file.write((char*)&str, sizeof(str));
      //file.close();

//    ifstream file;
//    file.open("tmp.bin", ios::binary);
//    while(file.read((char*)&str, sizeof(str)))
//    {
//        cout << str << endl;
//        cout << "Length: " << str.length() << endl;
//        cout << "Capacity: " << str.capacity() << endl;
//
//    }
//    file.close();


//    char str1[20];
//    char str2[20];
//    cin >> str1;
//    cin >> str2;
//    cout << str1 << endl;
//    cout << str2 << endl;
//    str2 = str1;
//    cout << str2 << endl;


    //DieselCar c1;
    //Database::AddInDatabase(c1);

//
//    for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
//    {
//        cout << it->GetBodyType().length() << endl;
//        cout << it->GetBodyType().capacity() << endl;
//    }


//
//    cout << '\n';

//    Database::DeleteFromDatabase(dieselCars[0]);
//
//   for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
//   {
//       cout << it->GetBrand() << ' ' << it->GetModel() << endl;
//   }

    return 0;
}