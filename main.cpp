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
    setlocale(LC_ALL, "ru_RU.UTF-8");
    wcout.imbue(locale("ru_RU.UTF-8"));
    wcin.imbue(locale("ru_RU.UTF-8"));

    //HybridCar car;
    //car.SetInfo();
//   // wcout << car.GetBodyType();
   // Database::AddInDatabase(car);

    Interface menu;
    menu.FirstMenu();

    //CarBrands c;
    //c.GetCarBrands();

//    wchar_t a1[50];
//    wchar_t a2[50];
//    //wchar_t a3[] = L"aston";
//     //wcin >> a2;
//     fgetws(a2,50,stdin); // считывание строки
//     cout << sizeof(a2) << endl;
//     a2[wcscspn(a2, L"\n")] = L'\0'; // замена символа
//     wcscpy(a1, a2); // копирование строки
//     wcout << a2 << endl;
//     wcout << a2 << endl;

//    wchar_t a1[] = L"asdfg";
//    wchar_t a2[] = L"bmw";
//    wchar_t a3[] = L"aston";
//
//    wchar_t b1[] = L"rx7";
//    wchar_t b2[] = L"апапр";
//    wchar_t b3[] = L"au3i";
//
//    wcout << '|' << setw(15) << left << a1 << '|' << setw(15) << left << b1 << '|' << endl;
//    wcout << '|' << setw(15) << left << a2 << '|' << setw(15) << left << b2 << '|' << endl;
//    wcout << '|' << setw(15) << left << a3 << '|' << setw(15) << left << b3 << '|' << endl;

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