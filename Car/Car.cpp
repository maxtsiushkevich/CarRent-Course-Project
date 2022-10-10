#include "Car.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Car :: Car()
{
    ofstream file;
    file.open("cars.txt");
    if (!file.is_open())
    {
        cout << "Error" << endl;
    }
    file.close();
    odometer = 0;
    cout << "Введите марку автомобиля: " << endl;
    cin >> brand;
    cout << "Введите модель автомобиля: " << endl;
    cin >> model;
}