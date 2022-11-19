#include "DieselCar.h"
#include <iostream>

DieselCar :: DieselCar() : OilCar() { }

DieselCar :: DieselCar(int odo) : Car(odo), OilCar(odo) { }

DieselCar :: ~DieselCar() { }