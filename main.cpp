#include <iostream>
#include <string>
#include <fstream>

#include "Car/Car.h"
#include "Car/ElectricCar.h"
#include "Car/DieselCar.h"
#include "Car/PetrolCar.h"
#include "Car/HybridCar.h"
#include "Car/OilCar.h"

#include "Database/Database.h"

//#include <ncurses.h>



using namespace std;

int main()
{
    //DieselCar d1(0);
    //Database::GetFromDatabase(d1);
    //cout << d1.GetId();
    return 0;
}










































































//int main()
//{
    //setlocale(LC_ALL, "ru");

    //Car car; // норм
    //ElectricCar ecar; // норм
    //OilCar ocar; // норм
    //DieselCar dcar; // норм

    //HybridCar hcar; // проблема
    //PetrolCar pcar; //

    //cout << sizeof(cr) << endl;

///    struct CarBrands c1;
///    ofstream file;
///    file.open("/Users/max/Desktop/CarRent/Files/CarBrands.bin", ofstream::binary | ofstream::app);
///    if (!file.is_open())
///        cout << "Error";
///
///        cin >> c1.num;
///        fflush(stdin);
///        cin.get(c1.brand, 30);
///        fflush(stdin);
///        cin.get(c1.country, 30);
///        file.write((char *) &c1, sizeof(CarBrands));
///    file.close();



//    OilCar c1;
//    ofstream file;
//    file.open("/Users/max/Desktop/CarRent/Files/OilCar.bin", ofstream::binary | ofstream::app);
//    if (!file.is_open())
//        cout << "Error";
//    file.write((char*)&c1, sizeof(OilCar));
//    file.close();





///   ifstream fil("/Users/max/Desktop/CarRent/Files/CarBrands.bin", ios::binary);
///   string str;
///    if (!fil.is_open())
///        cout << "Error";
///    else
///    {
///        while ( fil.read((char*)&c1, sizeof(CarBrands)))
///        {
///            cout << c1.num << ' ';
///            cout << c1.brand << ' ';
///            cout << c1.country << ' ' << endl;
///        }
///    }
///    fil.close();


    //cout << "Car" << sizeof(Car) << endl;
    //cout << "GasCar" << sizeof(GasCar) << endl;
    //cout << "ElectricCar" << sizeof(ElectricCar) << endl;
    //cout << "OilCar" << sizeof(OilCar) << endl;
    //cout << "HybridCar" << sizeof(HybridCar) << endl;

//}

