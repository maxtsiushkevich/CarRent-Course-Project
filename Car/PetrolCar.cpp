#include "PetrolCar.h"
#include <iostream>

PetrolCar :: PetrolCar() : OilCar()
{
    int choice;
    cout << "Марка бензина: " << endl;
    cout << "1 - 80\n"
            "2 - 92\n"
            "3 - 95\n"
            "4 - 98\n";
    cin >> choice;
    while (choice > 4 || choice < 0)
    {
        cout << "Ошибка. Введите еще раз: ";
        cin >> choice;
    }
    switch (choice)
    {
        case 1: petrolType = 80; break;
        case 2: petrolType = 92; break;
        case 3: petrolType = 95; break;
        case 4: petrolType = 98; break;
    }
}

PetrolCar :: PetrolCar (int odo) : OilCar(0) { odometer = odo; }

PetrolCar :: ~PetrolCar() { }

int PetrolCar :: GetPetrolType() { return petrolType; }