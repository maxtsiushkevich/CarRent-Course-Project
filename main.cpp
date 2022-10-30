#include <iostream>
#include "Car/Car.h"
#include "Car/ElectricCar.h"
#include "Car/HybridCar.h"
#include "Car/OilCar.h"
#include "Car/FileWorker.h"
#include <string>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    //OilCar c1;

//    ofstream file;
//    file.open("/Users/max/Desktop/CarRent/Files/OilCar.txt", ofstream::app);
//    if (!file.is_open())
//        cout << "Error";
//    file.write((char*)&c1, sizeof(OilCar));
//    file.close();


//    ifstream fil;
//    fil.open("/Users/max/Desktop/CarRent/Files/OilCar.txt");
//    //fil.seekg(0, ios::beg);
//    if (!fil.is_open())
//        cout << "Error";
//    else
//    {
//        OilCar car(0);
//        fil.read((char*)&car, sizeof(OilCar));
//        cout << car.GetBrand() << endl;
//    }
//    fil.close();



    ifstream file("/Users/max/Desktop/CarRent/Files/OilCar.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    else
    {
        OilCar c1(0);
        file.read((char*)&c1, sizeof(OilCar));
        cout << c1.manufacturedYear << endl;
    }
    file.close();


    //cout << "Car" << sizeof(Car) << endl;
    //cout << "GasCar" << sizeof(GasCar) << endl;
    //cout << "ElectricCar" << sizeof(ElectricCar) << endl;
    //cout << "OilCar" << sizeof(OilCar) << endl;
    //cout << "HybridCar" << sizeof(HybridCar) << endl;

}

