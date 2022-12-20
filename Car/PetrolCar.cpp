#include "PetrolCar.h"
#include <iostream>
#include "../Exception/Exception.h"

PetrolCar::PetrolCar() : OilCar() {
    petrolType = 0;
}

void PetrolCar::SetInfo() {
    OilCar::SetInfo();
    int choice;
    cout << "Марка бензина: " << endl;
    cout << "1 - 80\n"
            "2 - 92\n"
            "3 - 95\n"
            "4 - 98\n";
    while (1) {
        try {
            cin >> choice;
            if (cin.fail())
                throw BadInputException("Введена не цифра");
            if (choice < 1 || choice > 4)
                throw Exception("Введен неверный пункт");
            break;
        }
        catch (BadInputException exp) {
            exp.Fix();
        }
        catch (Exception exp) {
            exp.Fix();
        }
    }
    switch (choice) {
        case 1:
            petrolType = 80;
            break;
        case 2:
            petrolType = 92;
            break;
        case 3:
            petrolType = 95;
            break;
        case 4:
            petrolType = 98;
            break;
    }
}
