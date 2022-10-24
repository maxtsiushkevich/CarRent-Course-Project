#include <iostream>
#include "Car/Car.h"
#include "Car/ElectricCar.h"
#include "Car/HybridCar.h"
#include "Car/OilCar.h"
#include <string>
#include <fstream>
#include "Interface/Interface.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    Interface interface;

    //OilCar c1;
    //c1.getBrand();

    //c1.writeInFile();

    //OilCar c2(0);
    //c2.printAllCars();

    //c2.writeInFile();

    //c2.readFromFile();
    //c2.printAllInfo();

    //int main()
    //{
    //    test_label(2);  // in label1
    //    test_label(2);  // in label2
    //}

    //Car c2(0);

    //ifstream carsFile("/Users/max/Desktop/CarRent/AllCars.bin", ios::binary);
    //if (!carsFile.is_open())
    //    cout << "Error";
    //carsFile.read((char*)&c2, sizeof(Car));
    //carsFile.close();
    //c2.printAll();

    //cout << "Car" << sizeof(Car) << endl;
    //cout << "GasCar" << sizeof(GasCar) << endl;
    //cout << "ElectricCar" << sizeof(ElectricCar) << endl;
    //cout << "OilCar" << sizeof(OilCar) << endl;
    //cout << "HybridCar" << sizeof(HybridCar) << endl;

}

