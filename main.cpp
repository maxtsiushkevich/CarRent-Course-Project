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
#include "Session/Session.h"
#include <locale>

#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    //HybridCar car;
    //car.SetInfo();
    //Database::AddInDatabase(car);

    //Session ses(1, 2, 150, 5);
    Interface menu;
    menu.FirstMenu();

    //int week = (22 - (22 % 7)) / 7;
    //cout << week << endl;
    //int cost = week * 2 * 6 + (22 - week * 7) * 2;
    //cout << cost << endl;
    //int month = (38 - (38 % 30)) / 30;
    //int week = ((38 - month * 30) - ((38 - month * 30) % 7)) / 7;
    //int cost = month * 2 * 26 + week * 2 * 6 + (38 - month * 30 - week * 7) * 2;
    //cout << cost << endl;
    //int a = (14 - 11) / 12;
    //cout << a;
    //time_t seconds = time(NULL);
    //tm* currentTime = localtime(&seconds);
    //cout << currentTime->tm_mday << endl;
    //cout << tm.tm_mday;
    //char buf[64];
    //strftime(buf, 64, "%d.%m.%Y", localtime(&tm));
    //cout << buf << endl;
    //Admin admin;
    //Interface menu;
    //DieselCar c1;
    //Database::AddInDatabase(c1);

//    vector<DieselCar> dieselCars;
//    Database::GetFromDatabase(dieselCars);


    //Database::DeleteFromDatabase(dieselCars[1]);
    //Database::GetFromDatabase(dieselCars);

//    for (auto it = dieselCars.begin(); it != dieselCars.end(); ++it)
//    {
//        cout << it->GetBrand() << ' ';
//        cout << it->GetModel() << endl;
//    }


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