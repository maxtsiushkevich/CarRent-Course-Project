#include "OilCar.h"
#include "Car.h"
#include <iostream>
#include <fstream>
#include "../Exception/Exception.h"

OilCar::OilCar() : Car() {
    volume = 0.0;
    consumption = 0.0;
}

void OilCar::SetInfo() {
    Car::SetInfo();
    cout << "Объем двигателя: " << endl;
    while (1) {
        try {
            cin >> volume;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (volume < 0 || volume > 8.5)
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
    cout << "Расход топлива на 100км: " << endl;
    while (1) {
        try {
            cin >> consumption;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (consumption < 0)
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
