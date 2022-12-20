#include "ElectricCar.h"
#include <iostream>
#include <fstream>
#include "../Exception/Exception.h"

ElectricCar::ElectricCar() {
    batteryCapacity = 0;
}

void ElectricCar::SetInfo() {
    Car::SetInfo();
    cout << "Объем батареи: " << endl;
    while (1) {
        try {
            cin >> batteryCapacity;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (batteryCapacity < 0)
                throw Exception("Введено неверное значение");
            break;
        }
        catch (BadInputException exp) {
            exp.Fix();
        }
        catch (Exception exp) {
            exp.Fix();
        }
    }
}