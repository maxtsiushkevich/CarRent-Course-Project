#include <iostream>
#include "Car/Car.h"
#include "Car/ElectricCar.h"
#include "Car/GasCar.h"
#include "Car/HybridCar.h"
#include "Car/OilCar.h"
#include <string>
#include <fstream>

using namespace std;

void mainMenu();
void authentication();


int main()
{
    setlocale(LC_ALL, "ru");

    //Car c1;
    //c1.writeInFile();
    OilCar c2;
    //OilCar c2(0);
    //c2.writeInFile();
    //c2.readFromFile();
    //c2.printAll();

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

/*
void mainMenu()
{
    cout << "1 - Войти в аккаунт"
            "2 - Доступные автомобили"
            "3 - Подбор автомобиля"
            "4 - ";

}

void authentication ()
{
    cout << "В";
}*/
